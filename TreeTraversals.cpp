#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void findInorder(BinaryTreeNode<int> *node, vector<int> &ans)
{
    if (!node)
        return;
    findInorder(node->left, ans);
    ans.push_back(node->data);
    findInorder(node->right, ans);
}

void findPreorder(BinaryTreeNode<int> *node, vector<int> &ans)
{
    if (!node)
        return;
    ans.push_back(node->data);
    findPreorder(node->left, ans);

    findPreorder(node->right, ans);
}

void findPostorder(BinaryTreeNode<int> *node, vector<int> &ans)
{
    if (!node)
        return;
    findPostorder(node->left, ans);

    findPostorder(node->right, ans);
    ans.push_back(node->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> in, pre, pos;
    findInorder(root, in);
    findPreorder(root, pre);
    findPostorder(root, pos);
    vector<vector<int>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);

    return ans;
}