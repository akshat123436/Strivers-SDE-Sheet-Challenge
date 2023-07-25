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

int findDiameter(TreeNode<int> *node, int &ans)
{
    if (!node)
        return 0;

    int leftHeight = 0, rightHeight = 0;

    if (node->left)
        leftHeight = 1 + findDiameter(node->left, ans);
    if (node->right)
        rightHeight = 1 + findDiameter(node->right, ans);

    ans = max(ans, leftHeight + rightHeight);

    return max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int ans = 0;
    findDiameter(root, ans);
    return ans;
}
