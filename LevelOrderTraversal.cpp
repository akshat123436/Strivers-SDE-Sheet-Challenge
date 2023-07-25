#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if (!root)
        return {};

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        auto cur = q.front();
        ans.push_back(cur->val);
        q.pop();
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }

    return ans;
}