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

void preorder(TreeNode<int> *node, int k, int &i, int &ans)
{
    if (!node)
        return;
    if (i > k)
        return;

    preorder(node->left, k, i, ans);
    i++;
    if (i == k)
    {
        ans = node->data;
        i++;
        return;
    }
    preorder(node->right, k, i, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    int ans = 0;
    int i = 0;
    preorder(root, k, i, ans);

    return ans;
}