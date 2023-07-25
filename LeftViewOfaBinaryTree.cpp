#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    queue<pair<TreeNode<int> *, int>> q;
    if (!root)
        return {};
    q.push({root, 0});
    int levelCounter = 0;
    vector<int> ans;
    while (!q.empty())
    {
        auto e = q.front();
        q.pop();
        TreeNode<int> *cur = e.first;
        int lvl = e.second;
        if (lvl == levelCounter)
        {
            ans.push_back(cur->data);
            levelCounter++;
        }
        if (cur->left)
            q.push({cur->left, lvl + 1});
        if (cur->right)
            q.push({cur->right, lvl + 1});
    }

    return ans;
}