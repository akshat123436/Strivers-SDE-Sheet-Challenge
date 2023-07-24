#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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

struct bstValues
{
    int minValue;
    int maxValue;
    int size;
    bool isBst;
    bstValues(int min, int max, int size, bool isBst)
    {
        minValue = min;
        maxValue = max;
        this->size = size;
        this->isBst = isBst;
    }
};

bstValues findBst(int &ans, TreeNode<int> *node)
{
    if (!node)
        return bstValues(1e9, -1, 0, true);
    //     cout << node->data << " " << (node->left ? node->left->data : 777) << " " << (node->right ? node->right->data : 777) << endl;
    bstValues l = findBst(ans, node->left);
    bstValues r = findBst(ans, node->right);

    int sizee = 0;
    if (!(l.isBst && r.isBst))
        return bstValues(0, 0, 0, false);
    if ((l.maxValue >= node->data) || (r.minValue <= node->data))
        return bstValues(0, 0, 0, false);
    ans = max(ans, 1 + l.size + r.size);
    return bstValues(min(min(l.minValue, r.minValue), node->data), max(max(l.maxValue, r.maxValue), node->data), 1 + l.size + r.size, true);
}

int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    int ans = 1;
    // vector<int> inorder;

    findBst(ans, root);
    // findIn(inorder, root);
    return ans;
}
