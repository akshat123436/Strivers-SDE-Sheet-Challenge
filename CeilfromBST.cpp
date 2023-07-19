#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void finder(BinaryTreeNode<int> *node, int x, int &ans)
{
    if (!node)
        return;
    if (node->data == x)
    {
        ans = x;
        return;
    }
    if (node->data < x)
    {
        finder(node->right, x, ans);
    }
    if (node->data > x)
    {
        ans = node->data;
        finder(node->left, x, ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    finder(node, x, ans);

    return ans;
}