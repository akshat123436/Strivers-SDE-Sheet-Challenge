#include <bits/stdc++.h>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/

TreeNode<int> *nodeMaker(vector<int> &postOrder, vector<int> &inOrder, int inStart, int inEnd, unordered_map<int, int> &inIndex, int &index)
{
    if (inStart > inEnd)
        return nullptr;
    int val = postOrder[index];
    index--;
    int inOrderIndex = inIndex[val];
    TreeNode<int> *current = new TreeNode<int>(val);

    current->right = nodeMaker(postOrder, inOrder, inOrderIndex + 1, inEnd, inIndex, index);
    current->left = nodeMaker(postOrder, inOrder, inStart, inOrderIndex - 1, inIndex, index);

    return current;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    // Write your code here.
    unordered_map<int, int> inIndex;
    int index = postOrder.size() - 1;
    for (int i = 0; i < inOrder.size(); i++)
        inIndex[inOrder[i]] = i;
    return nodeMaker(postOrder, inOrder, 0, inOrder.size() - 1, inIndex, index);
}
