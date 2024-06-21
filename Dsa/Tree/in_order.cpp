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
            cout << "Value inserted as root node in tree " << endl;
        }
        else
        {
            TreeNode *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->value == n->value)
                {
                    cout << "No duplicate allowed " << endl;
                    return;
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
    void print_postorder(TreeNode *n)
    {
        if(n == NULL)
        {
            return;
            
        }
        print_postorder(n->left);
        cout<<n->value<<" ";
        print_postorder(n->right);
    }
};
int main()
{
    
    BST s;
    int data;
    int option;
    do
    {
        cout << endl<<"What operation do you want to performed ?"
             << "select Option Number. Enter 0to exit. " << endl;
        cout << "Enter 1 to insert Node" << endl;
        cout << "Enter 2 to Search Node" << endl;
        cout << "Enter 3 to Delete Node" << endl;
        cout << "Enter 4 to Print Node" << endl;
        cout << "Enter 5 to Cleart Screen" << endl;
        cout << "Enter 0 to Exit " << endl;

        cin >> option;
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter value to insert in Binary search tree = " << endl;
            cin >> data;
            new_node->value = data;
            s.insert(new_node);
            break;
        case 2:
            cout << "Search Node" << endl;
            // code
            break;
        case 3:
            cout << "DELETE" << endl;
            // code
            break;
        case 4:
            cout << "PRINT and TRAVERSE" << endl;
            s.print(s.root, 5);
            s.print_postorder(s.root);
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter proper option number " << endl;
        }
    } while (option != 0);

    return 0;
}
