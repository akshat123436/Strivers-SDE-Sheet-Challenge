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

void findSmallest(TreeNode<int> *node, int x, int &ans)
{
    if (!node)
        return;
    if (node->val <= x)
    {
        ans = node->val;
        findSmallest(node->right, x, ans);
    }
    else
    {
        findSmallest(node->left, x, ans);
    }
}

int floorInBST(TreeNode<int> *root, int X)
{
    int ans;
    findSmallest(root, X, ans);
    return ans;
}