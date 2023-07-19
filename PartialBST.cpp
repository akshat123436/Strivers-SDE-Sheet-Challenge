#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (!root)
        return true;
    if (root->left)
    {
        if (root->left->data <= root->data)
        {
        }
        else
        {
            return false;
        }
    }
    if (root->right)
    {
        if (root->right->data >= root->data)
        {
        }
        else
        {
            return false;
        }
    }

    return validateBST(root->left) && validateBST(root->right);
}