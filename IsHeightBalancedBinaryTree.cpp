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

pair<bool, int> isBalanced(BinaryTreeNode<int> *node)
{
    if (!node)
        return {true, 0};

    auto left = isBalanced(node->left);
    auto right = isBalanced(node->right);

    return {(abs((left.second) - (right.second)) <= 1 && (left.first) && (right.first) ? true : false), 1 + max(left.second, right.second)};
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return (isBalanced(root)).first;
}