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
TreeNode<int> *f(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;
    if (start == end)
        return new TreeNode<int>(arr[start]);

    int mid = (start + end) / 2;

    TreeNode<int> *cur = new TreeNode<int>(arr[mid]);

    cur->left = f(arr, start, mid - 1);
    cur->right = f(arr, mid + 1, end);
    return cur;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.

    return f(arr, 0, n - 1);
}