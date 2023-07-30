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

typedef TreeNode<int> *t;

void s(t r, t p, t l, bool &q, t &ans)
{

    if (!r)
    {

        return;
    }

    if (r->data == l->data)
    {

        r->left = p;

        q = 1;

        ans = r;

        return;
    }

    s(r->left, r, l, q, ans);

    if (q)
    {

        r->left = p;

        return;
    }

    s(r->right, r, l, q, ans);

    if (q)
    {

        if (r->left)
        {

            r->right = r->left;
        }

        else
        {

            r->right = NULL;
        }

        r->left = p;

        return;
    }
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    // Write your code here.
    bool q = 0;

    t ans = NULL;

    s(root, NULL, leaf, q, ans);

    return ans;
}
