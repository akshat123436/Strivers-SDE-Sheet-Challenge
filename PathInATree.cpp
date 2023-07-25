#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

void dfs(TreeNode<int> *node, int x, vector<int> &ds, vector<int> &ans)
{
    if (!node)
        return;
    if (node->data == x)
    {
        ds.push_back(x);
        ans = ds;
        return;
    }
    ds.push_back(node->data);
    dfs(node->left, x, ds, ans);
    dfs(node->right, x, ds, ans);
    ds.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    vector<int> ds;

    dfs(root, x, ds, ans);

    return ans;
}
