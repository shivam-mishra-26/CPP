#include<iostream>
using namespace std;
#define SPACE 10
class node
{
    public :
        int data;
        node *right;
        node *left;

        node()
        {
            data=0;
            right=NULL;
            left=NULL;
        }
        node (int n)
        {
            data=n;
            right=NULL;
            left=NULL;
        }
};
class buildTree
{   
    public :

        node *root;
        buildTree()
        {
            root=NULL;
        }
        buildTree(node*n)
        {
            root=n;
        }
        bool isEmpty()
        {
            if (root == NULL)
            {
                return true;
            }
            else
                return false;
        }
        node *minvalue(node* n)
        {
            node *ptr=n;
            ptr=ptr->left;
            while(ptr!=NULL)
            {
               ptr=ptr->right; 
            }
            return ptr;
        }
        node *deleteNode(node *r,int v)
        {
            if(r==NULL)
            {
                return NULL;
            }
            else if(v < r->data)
            {
                r->left = deleteNode(r->left,v);
            }
             else if(v > r->data)
            {
                r->right = deleteNode(r->right,v);
            }
            else
            {
                if(r->left == NULL)
                {
                    node *temp=r->right;
                    delete r;
                    return temp;
                }
                else if(r->right == NULL)
                {
                    node *temp=r->left;
                    delete r;
                    return temp;
                }
                else
                {
                    node *temp=minvalue(r->right);
                    r->data=temp->data;
                    r->right=deleteNode(r->right,temp->data);

                }
            }

        }
        node *insert(node* n)
        {
            if(root==NULL)
            {
                return root;
            }
            
            else
            {
                node *ptr=root;
                while(ptr!=NULL)
                {
                    if(ptr->data==n->data)
                    {
                        cout<<"NO duplicates allowed"<<endl;
                    }
                    else if((ptr->data>n->data) &&(ptr->left==NULL) )
                    {
                        ptr->left=n;
                        cout<<"Value inserted"<<endl;
                        break;
                    }
                    else if((ptr->data>n->data)  )
                    {
                        ptr=ptr->left;
                    }
                    else if((ptr->data<n->data) &&(ptr->right==NULL) )
                    {
                        ptr->right=n;
                        cout<<"Value inserted"<<endl;
                        break;
                    }
                    else
                    {
                        ptr=ptr->right;
                    }
                }
            }
        }
        node *search_node(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            node *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->data == v)
                {
                    return ptr;
                }
                else if (ptr->data > v)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            return NULL;
        }
    }
        void print(node *r, int space)
        {
            if (r == NULL)
                return;
            space += SPACE;
            print(r->right, space);
            cout << endl;
            for (int i = SPACE; i < space; i++)
            {
                cout << " ";
            }
            cout << r->data << "\n";
            print(r->left, space);
        }
        void print_preorder(node *n)
        {
            if (n == NULL)
            {
                return;
            }
            cout << n->data << " ";
            print_preorder(n->left);
            print_preorder(n->right);
        }
        void print_postorder(node *r)
        {
            if (r == NULL)
            {
                return;
            }
            print_postorder(r->left);
            print_postorder(r->right);
            cout << r->data << " ";
        }
        void print_inorder(node *n)
        {
            if (n == NULL)
            {
                return;
            }
            print_inorder(n->left);
            cout << n->data << " ";
            print_inorder(n->right);
        }
};
int main()
{
    buildTree bt;
    int value;
    int option;
    do
    {
        cout << "What operation do you want to performed ?"
             << "select Option Number. Enter 0 to exit. " << endl;
        cout << "Enter 1 to insert Node" << endl;
        cout << "Enter 2 to Search Node" << endl;
        cout << "Enter 3 to Delete Node" << endl;
        cout << "Enter 4 to Print Node" << endl;
        cout << "Enter 5 to find height of tree "<<endl;
        cout << "Enter 6 to Cleart Screen" << endl;
        cout << "Enter 0 to Exit " << endl;
        cin>>option;
        node *new_node=new node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter value to insert in Binary search tree = ";
            cin >> value;
            new_node->data = value;
            bt.insert(new_node);
            break;
        case 3:
            cout<<"DELETE"<<endl;
            cout<<"Enter the value to delete in BST:- ";
            cin>>value;
            new_node = bt.search_node(value);
            if(new_node!=NULL)
            {
                bt.deleteNode(bt.root,value);
                cout<<"Value Deleted"<<endl;
            }
            else
            {
                cout<<"Value Not found"<<endl;
            }
            break;
        case 4:
            cout << "PRINT and TRAVERSE" << endl;
            bt.print(bt.root, 5);
            cout<<"In order   : ";
            bt.print_inorder(bt.root);
            cout<<endl<<endl;
            cout<<"Post order : ";
            bt.print_postorder(bt.root);
            cout<<endl<<endl;
            cout<<"Pre order  : ";
            bt.print_preorder(bt.root);
            cout<<endl<<endl;

            break;
        default:
            cout << "Enter proper option number " << endl;
        }
    }while(option!=0);

}
