#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void findPostOrder(TreeNode *node, vector<int> &ans)
{
    if (!node)
        return;

    findPostOrder(node->left, ans);
    findPostOrder(node->right, ans);
    ans.push_back(node->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    findPostOrder(root, ans);
    return ans;
}