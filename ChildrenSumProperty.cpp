#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int balancedHeight(BinaryTreeNode<int> *node)
{
    if (!node)
        return 0;
    int childrenSum = 0;
    if (node->left)
        childrenSum += balancedHeight(node->left);
    if (node->right)
        childrenSum += balancedHeight(node->right);
    if (childrenSum > node->data)
        node->data = childrenSum;
    return node->data;
}

void changeHeights(BinaryTreeNode<int> *node)
{
    if (!node)
        return;
    int childrenSum = 0;
    if (node->left)
        childrenSum += node->left->data;
    if (node->right)
        childrenSum += node->right->data;
    if (childrenSum > node->data)
        node->data = childrenSum;
    else
    {
        if (node->left)
            node->left->data = node->data;
        if (node->right)
            node->right->data = node->data;
    }
    changeHeights(node->left);
    changeHeights(node->right);
}

void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    changeHeights(root);
    balancedHeight(root);
}