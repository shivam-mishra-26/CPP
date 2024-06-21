#include <iostream>
#define SPACE 10
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }

    BST(TreeNode *n)
    {
        root = n;
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

    void insert(TreeNode *n)
    {

        if (root == NULL)
        {
            root = n;
            cout << "Value inserted as root node " << endl;
        }
        else
        {
            TreeNode *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->value == n->value)
                {
                    cout << "No duplicate allowed " << endl;
                }
                else if ((ptr->value > n->value) && (ptr->left == NULL))
                {
                    ptr->left = n;
                    cout << "Value inserted to the left" << endl;
                    break;
                }
                else if (ptr->value > n->value)
                {
                    ptr = ptr->left;
                }
                else if ((ptr->value < n->value) && (ptr->right == NULL))
                {
                    ptr->right = n;
                    cout << "Value inserted to the right" << endl;
                    break;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
        }
    }
    TreeNode *search_node(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->value == v)
                {
                    return ptr;
                }
                else if (ptr->value > v)
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
    void print(TreeNode *r, int space)
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
        cout << r->value << "\n";
        print(r->left, space);
    }
    void print_preorder(TreeNode *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->value << " ";
        print_preorder(n->left);
        print_preorder(n->right);
    }
    void print_postorder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        print_postorder(r->left);
        print_postorder(r->right);
        cout << r->value << " ";
    }
    void print_inorder(TreeNode *n)
    {
        if (n == NULL)
        {
            return;
        }
        print_inorder(n->left);
        cout << n->value << " ";
        print_inorder(n->right);
    }
    int height(TreeNode* r)
    {
        if (r == NULL)
            return -1;
        else 
        {
            int left_height=height(r->left);
            int right_height=height(r->right);

            if( left_height > right_height)
            {
                return (left_height+1);
            }
            else
            {
                return (right_height+1);
            }
        }
    }
};
int main()
{
    BST s;
    int data;
    int option;
    do
    {
        cout << "What operation do you want to performed ?"
             << "select Option Number. Enter 0to exit. " << endl;
        cout << "Enter 1 to insert Node" << endl;
        cout << "Enter 2 to Search Node" << endl;
        cout << "Enter 3 to Delete Node" << endl;
        cout << "Enter 4 to Print Node" << endl;
        cout << "Enter 5 to find height of tree "<<endl;
        cout << "Enter 6 to Cleart Screen" << endl;
        cout << "Enter 0 to Exit " << endl;

        cin >> option;
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter value to insert in Binary search tree = ";
            cin >> data;
            new_node->value = data;
            s.insert(new_node);
            break;
        case 2:
            cout << "Search Node called" << endl;
            cout<<"Enter value to find node exist or not"<<endl;
            cin>>data;
            new_node=s.search_node(data);
            if(new_node == NULL)
            {
                cout<<"Node not Exist"<<endl;
            }
            else
            {
                cout<<"Node Exist"<<endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            // code
            break;
        case 4:
            cout << "PRINT and TRAVERSE" << endl;
            s.print(s.root, 5);
            cout<<"In order   : ";
            s.print_inorder(s.root);
            cout<<endl<<endl;
            cout<<"Post order : ";
            s.print_postorder(s.root);
            cout<<endl<<endl;
            cout<<"Pre order  : ";
            s.print_preorder(s.root);
            cout<<endl<<endl;

            break;
        case 5:
            cout<<"TREE HEIGHT "<<endl;
            cout<<"Height : "<<s.height(s.root)<<endl;
            break;
        case 6:
            system("clear");
            break;
        default:
            cout << "Enter proper option number " << endl;
        }
    } while (option != 0);

    return 0;
}