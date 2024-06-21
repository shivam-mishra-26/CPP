#include <iostream>
using namespace std;
class node
{
    public:
        int data;
        node *left;
        node *right;

        node ()
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
class Bst
{
    public:
        node *root;
        Bst()
        {
            root=NULL;
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
    void insert(node *n)
    {
        if (root==NULL)
        {
            root=n;
            cout<<"Node inserted"<<endl;
        }
       else
       {
           node *ptr =root;
           while(ptr != NULL)
           {
            if(ptr == n)
            {
                cout<<"Duplicate are not allowed"<<endl;
            }
            else if((ptr->data > n->data) &&  (ptr->left == NULL))
            {
                ptr->left = n;
                cout << "Value inserted to the left" << endl;
                break;
            }
            else if(ptr->data > n->data)
            {
                ptr=ptr->left;
            }
            else if ((ptr->data < n->data) && (ptr->right == NULL))
            {
                ptr->right = n;
                cout << "Value inserted to the right node" << endl;
                break;
            }
            else
            {
                ptr = ptr->right;
            }
            
           }
       }
    }
    void insertion(node *n)
    {
        
    }
        


};