#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long f(long long &ans, TreeNode<int> *node)
{
    if (!node)
        return 0;
    long long leftValue = f(ans, node->left);
    long long rightValue = f(ans, node->right);
    long long totalValue = 1LL * (leftValue) + node->val + rightValue;
    if (node->left && node->right)
    {
        ans = max(ans, 1LL * (node->val));
        ans = max(ans, totalValue);
        ans = max(ans, leftValue + node->val);
        ans = max(ans, rightValue + node->val);
    }

    long long returnValue = max(1LL * (node->val), node->val + rightValue);
    return max(node->val + leftValue, returnValue);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long ans = -1;
    f(ans, root);

    return ans;
}