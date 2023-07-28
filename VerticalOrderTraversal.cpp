#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int, vector<int>> verticalNodes;

    if (!root)
        return {};

    queue<pair<TreeNode<int> *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto cur = q.front().first;
        int currentX = q.front().second;
        q.pop();
        verticalNodes[currentX].push_back(cur->data);

        if (cur->left)
            q.push({cur->left, currentX - 1});
        if (cur->right)
            q.push({cur->right, currentX + 1});
    }
    vector<int> ans;
    for (auto &a : verticalNodes)
    {
        for (auto b : a.second)
        {
            ans.push_back(b);
        }
    }

    return ans;
}