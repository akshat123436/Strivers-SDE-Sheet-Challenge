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
void findPreOrder(TreeNode *node, vector<int> &ans)
{
    if (!node)
        return;

    ans.push_back(node->data);
    findPreOrder(node->left, ans);
    findPreOrder(node->right, ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    findPreOrder(root, ans);
    return ans;
}