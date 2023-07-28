#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void preorder(vector<int> &ans, TreeNode<int> *node)
{
    if (!node)
        return;
    preorder(ans, node->left);
    if (!(node->left || node->right))
        ans.push_back(node->data);
    preorder(ans, node->right);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *cur = root;
    if (!root)
        return {};
    vector<int> ans;
    if (root->left || root->right)
        ans.push_back(root->data);
    cur = cur->left;
    while (cur)
    {
        if (cur->left || cur->right)
            ans.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }

    preorder(ans, root);

    stack<int> s;
    cur = root->right;
    while (cur)
    {
        if (cur->left || cur->right)
            s.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}