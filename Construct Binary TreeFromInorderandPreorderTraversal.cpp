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
TreeNode<int> *createTree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int &index, unordered_map<int, int> &mp)
{
    if (inStart > inEnd)
        return nullptr;
    int val = preorder[index];
    index++;
    TreeNode<int> *cur = new TreeNode<int>(val);
    int currentIndex = mp[val];

    cur->left = createTree(inorder, preorder, inStart, currentIndex - 1, index, mp);
    cur->right = createTree(inorder, preorder, currentIndex + 1, inEnd, index, mp);

    return cur;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int index = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return createTree(inorder, preorder, 0, inorder.size() - 1, index, mp);
}