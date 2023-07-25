#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

leftoright
5
2
7
6

righttoleft
3

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    stack<BinaryTreeNode<int> *> leftToRight, rightToLeft;
    if (!root)
        return {};
    leftToRight.push(root);
    vector<int> ans;
    while (!leftToRight.empty() || !rightToLeft.empty())
    {
        if (!leftToRight.empty())
        {
            while (!leftToRight.empty())
            {
                auto a = leftToRight.top();
                leftToRight.pop();
                ans.push_back(a->data);
                if (a->left)
                    rightToLeft.push(a->left);
                if (a->right)
                    rightToLeft.push(a->right);
            }
        }
        else
        {
            while (!rightToLeft.empty())
            {
                auto a = rightToLeft.top();
                rightToLeft.pop();
                ans.push_back(a->data);
                if (a->right)
                    leftToRight.push(a->right);
                if (a->left)
                    leftToRight.push(a->left);
            }
        }
    }

    return ans;
}
