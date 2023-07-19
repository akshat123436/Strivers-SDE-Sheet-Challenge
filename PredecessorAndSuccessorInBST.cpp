#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void predecessor(int &ret, BinaryTreeNode<int> *node, int key)
{
    if (!node)
        return;
    if (node->data < key)
    {
        ret = node->data;
        predecessor(ret, node->right, key);
    }
    else
    {
        predecessor(ret, node->left, key);
    }
}

void successor(int &ret, BinaryTreeNode<int> *node, int key)
{
    if (!node)
        return;
    if (node->data > key)
    {
        ret = node->data;
        successor(ret, node->left, key);
    }
    else
    {
        successor(ret, node->right, key);
    }
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int suc = -1, pred = -1;
    successor(suc, root, key);
    predecessor(pred, root, key);
    return {pred, suc};
}
