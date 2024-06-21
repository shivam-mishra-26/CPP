#include <iostream>
using namespace std;
class node
{
    public:
        int value;
        node *left;
        node *right;

        node()
        {
            value=0;
            left=NULL;
            right=NULL;
        }
        node(int v)
        {
            value=v;
             left=NULL;
            right=NULL;
        }
};
class bst
{
    public:   
        node *root;
        bst()
        {
            root=NULL;
        }
        bst(node *n)
        {
            root=n;
        }
        bool is_empty()
        {
            if(root == NULL )
            {
                 return true;
            }
            else
            {
                return false;
            }
        }
        void implement(node *n)
        {
            if(root == NULL)
            {
                root=n;
            }
        }
};