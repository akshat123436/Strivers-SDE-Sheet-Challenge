#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *nodeMaker(vector<int> &preorder, int start, int end)
{
    if (start <= -1 || end <= -1 || start > end)
        return nullptr;

    int val = preorder[start];
    TreeNode<int> *current = new TreeNode<int>(val);
    int index = -1;
    for (int i = start + 1; i <= end; i++)
    {
        if (preorder[i] > val)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        index = end + 1;
    current->left = nodeMaker(preorder, start + 1, index - 1);
    current->right = nodeMaker(preorder, index, end);

    return current;
}
void po(TreeNode<int> *node)
{
    if (!node)
        return;
    // cout<< node->data << endl;
    po(node->left);
    po(node->right);
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    return nodeMaker(preOrder, 0, preOrder.size() - 1);
}