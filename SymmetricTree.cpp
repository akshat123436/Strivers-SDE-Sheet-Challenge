/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/
void makeInvertedTree(BinaryTreeNode<int> *original, BinaryTreeNode<int> *inverted)
{
    if (!original)
        return;
    if (original->right)
        inverted->left = new BinaryTreeNode<int>(original->right->data);
    if (original->left)
        inverted->right = new BinaryTreeNode<int>(original->left->data);

    makeInvertedTree(original->left, inverted->right);
    makeInvertedTree(original->right, inverted->left);
}

bool compare(BinaryTreeNode<int> *original, BinaryTreeNode<int> *inverted)
{
    if (!original || !inverted)
    {
        if (original || inverted)
            return false;
        return true;
    }

    if (original->data != inverted->data)
        return false;
    return compare(original->left, inverted->left) && compare(original->right, inverted->right);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return true;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);

    makeInvertedTree(root, newNode);
    return compare(root, newNode);
}