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

class BSTiterator
{
    stack<TreeNode<int> *> s;

public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        s.push(root);

        while (s.top()->left)
        {
            s.push(s.top()->left);
        }
    }

    int next()
    {
        // write your code here
        if (s.empty())
            return -1;
        TreeNode<int> *temp = s.top();
        int val = temp->data;
        s.pop();
        if (temp->right)
        {
            s.push(temp->right);
            while (s.top()->left)
                s.push(s.top()->left);
        }
        return val;
    }

    bool hasNext()
    {
        // write your code here
        return !s.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/