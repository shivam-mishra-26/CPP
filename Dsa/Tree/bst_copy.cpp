#include <iostream>
using namespace std;
class node
{
    public :
        int data;
        node *left;
        node *right;
        node()
        {
            data=0;
            left=NULL;
            right=NULL;
        }
        node(int v)
        {
            data=v;
            left=NULL;
            right=NULL;
        }

};
class insert
{
    public:

        node *root;
        insert()
        {
            root=NULL;
        }
        insert(node *n)
        {
            root=n;
        }
        bool isEmpty()
        {
            if(root==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void put(node *n)
        {
            if(root==NULL)
            {
                root=n;
                cout << "Value inserted as root node " << endl;
            }
            else
            {
                node *ptr=root;
                while(ptr!=NULL)
                {
                    
                    if (ptr->data == n->data)
                    {
                        cout << "No duplicate allowed " << endl;
                        return;
                    }
                    else if(ptr->data>n->data && ptr->left==NULL)
                    {
                        ptr->left=n;
                        cout << "Value inserted to the left" << endl;
                        break ;
                    }
                    else if(ptr->data>n->data)
                    {
                        ptr=ptr->left;
                    }
                    else if(ptr->data<n->data && ptr->right==NULL)
                    {
                        ptr->right=n;
                        cout << "Value inserted to the left" << endl;
                        break;
                    }
                    else
                    {
                        ptr=ptr->right;
                    }

                }
            }
        }
        void inorder(node *n)
        {
            if(n==NULL)
            {
                return;
            }
            inorder(n->left);
            cout<<n->data<<" ";
            inorder(n->right);
            
        }
};
int main()
{
    insert s;
    int option;
    int value;
    do
    {
        cout<<"Enter 1 to insert value "<<endl;
        cout<<"Enter 2 to print BS "<<endl;
        cout<<"Enter 0 to exit "<<endl;

        cin >> option;
        node *nodes=new node();
        switch(option)
        {
            case 1:
                cout<<"Enter data to insert= ";
                cin>>value;
                nodes->data=value;
                s.put(nodes);
                break;
            case 2:
                cout<<"Binary search tree is"<<endl;
                s.inorder(s.root);
                cout<<endl<<endl;
        }
    } while (option!=0);
    
}