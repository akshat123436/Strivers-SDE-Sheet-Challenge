#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);
        for (int i = 0; i < size; i++)
        {
            auto topMost = q.front();
            q.pop();
            if (topMost->left)
                q.push(topMost->left);
            if (topMost->right)
                q.push(topMost->right);
        }
    }
    return ans;
}