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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if (!root)
        return -1;
    if (root->data == x || root->data == y)
        return root->data;
    int leftValue = lowestCommonAncestor(root->left, x, y);
    int rightValue = lowestCommonAncestor(root->right, x, y);
    if (leftValue == -1 && rightValue == -1)
        return -1;
    else if (leftValue != -1 && rightValue != -1)
        return root->data;
    else
        return max(leftValue, rightValue);
}