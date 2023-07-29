#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void createPreorder(TreeNode<int> **prev, TreeNode<int> *node)
{
    if (!node)
        return;
    createPreorder(prev, node->right);
    createPreorder(prev, node->left);
    node->right = *prev;
    node->left = nullptr;
    *prev = node;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = nullptr;
    createPreorder(&prev, root);

    return prev;
}