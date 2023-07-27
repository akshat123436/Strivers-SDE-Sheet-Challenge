#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BstIterator
{
    stack<BinaryTreeNode<int> *> ascending, descending;

public:
    BstIterator(BinaryTreeNode<int> *root)
    {
        ascending.push(root);
        while (ascending.top()->left)
            ascending.push(ascending.top()->left);

        descending.push(root);
        while (descending.top()->right)
            descending.push(descending.top()->right);
    }

    pair<int, int> values()
    {
        if (ascending.empty())
            return {-1, -1};
        return {ascending.top()->data, descending.top()->data};
    }

    void removeSmall()
    {
        BinaryTreeNode<int> *temp = ascending.top();
        ascending.pop();

        if (temp->right)
        {
            ascending.push(temp->right);

            while (ascending.top()->left)
                ascending.push(ascending.top()->left);
        }
    }
    void removeBig()
    {
        BinaryTreeNode<int> *temp = descending.top();
        descending.pop();

        if (temp->left)
        {
            descending.push(temp->left);
            while (descending.top()->right)
                descending.push(descending.top()->right);
        }
    }

    bool sumPossible(int k)
    {
        while (ascending.size() && descending.size())
        {
            auto vals = this->values();
            if (vals.first >= vals.second)
                return false;
            int sum = vals.first + vals.second;
            if (sum == k)
                return true;
            else if (sum > k)
            {
                this->removeBig();
            }
            else
            {
                this->removeSmall();
            }
        }
        return false;
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BstIterator *bi = new BstIterator(root);
    return bi->sumPossible(k);
}