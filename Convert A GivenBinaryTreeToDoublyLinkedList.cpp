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

*************************************************************/
// pair<BinaryTreeNode<int> *, BinaryTreeNode<int> *> makeDoubly(BinaryTreeNode<int> *cur){
//     if(!cur) return {nullptr, nullptr};
//
// auto l = makeDoubly(cur->left);
// if(l.second)
// l.second->right = cur;
// cur->left = l.second;
// auto r = makeDoubly(cur->right);
// cur->right = r.first;
// if(r.first)
// r.first->left = cur;
// auto returnLeft = l.first;
// auto returnRight = r.second;
// if(!returnLeft) returnLeft = cur;
// if(!returnRight) returnRight = cur;
// return {returnLeft, returnRight};

// }

void preorderMaker(BinaryTreeNode<int> *node, BinaryTreeNode<int> **head, BinaryTreeNode<int> **prev)
{
    if (!node)
        return;

    preorderMaker(node->left, head, prev);
    if (*prev)
    {
        node->left = *prev;
        (*prev)->right = node;
    }
    else
        (*head) = node;
    (*prev) = node;

    preorderMaker(node->right, head, prev);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // if(!root) return nullptr;
    // BinaryTreeNode<int> *anyNode = (makeDoubly(root)).second;

    // return anyNode;
    BinaryTreeNode<int> *head = nullptr;
    BinaryTreeNode<int> *prev = nullptr;

    preorderMaker(root, &head, &prev);

    return head;
}