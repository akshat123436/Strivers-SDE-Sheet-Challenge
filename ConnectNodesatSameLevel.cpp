#include <bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public :
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    queue<pair<BinaryTreeNode<int> *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        BinaryTreeNode<int> *cur = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if (!q.empty())
        {
            if (lvl == q.front().second)
            {
                cur->next = q.front().first;
            }
        }

        if (cur->left)
            q.push({cur->left, lvl + 1});
        if (cur->right)
            q.push({cur->right, lvl + 1});
    }
}