#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return {};
    map<int, pair<int, int>> mp;

    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 1}});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        auto cur = temp.first;
        int curLevel = temp.second.second;
        int curIndex = temp.second.first;
        if (mp[curIndex].second == 0)
            mp[curIndex] = {cur->val, curLevel};

        if (cur->left)
            q.push({cur->left, {curIndex - 1, curLevel + 1}});
        if (cur->right)
            q.push({cur->right, {curIndex + 1, curLevel + 1}});
    }
    vector<int> ans;
    for (auto &it : mp)
    {
        ans.push_back(it.second.first);
    }

    return ans;
}