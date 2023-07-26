#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void finder(TreeNode<int> *node, int k, int &ans, int &count)
{
    if (!node)
        return;
    if (count >= k)
        return;
    finder(node->right, k, ans, count);
    count++;
    if (k == count)
        ans = node->data;
    finder(node->left, k, ans, count);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    int ans = -1;
    int count = 0;
    finder(root, k, ans, count);

    return ans;
}
