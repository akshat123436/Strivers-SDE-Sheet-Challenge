#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    map<int, int> bottomIndexNodes;

    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int indexNumber = temp.second;
        BinaryTreeNode<int> *current = temp.first;
        bottomIndexNodes[indexNumber] = current->data;

        if (current->left)
            q.push({current->left, indexNumber - 1});
        if (current->right)
            q.push({current->right, indexNumber + 1});
    }

    vector<int> ans;

    for (auto &a : bottomIndexNodes)
    {
        ans.push_back(a.second);
    }

    return ans;
}
