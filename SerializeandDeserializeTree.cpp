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

string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    if (!root)
    {
        root = new TreeNode<int>(-1);
    }

    queue<TreeNode<int> *> q;
    string ans;
    q.push(root);
    while (!q.empty())
    {
        int val = q.front()->data;
        auto temp = q.front();
        q.pop();

        ans += to_string(val);
        ans.push_back(' ');
        if (val != -1)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            else
            {
                q.push(new TreeNode<int>(-1));
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            else
            {
                q.push(new TreeNode<int>(-1));
            }
        }
    }

    return ans;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    //    Write your code here for deserializing the tree
    string temp;
    int i = 0;
    while (serialized[i] != ' ')
    {
        temp.push_back(serialized[i]);
        i++;
    }
    i++;
    if (temp == "-1")
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(stoi(temp));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        string temp;
        while (serialized[i] != ' ')
        {
            temp.push_back(serialized[i]);
            i++;
        }
        i++;
        if (temp != "-1")
        {
            TreeNode<int> *child = new TreeNode<int>(stoi(temp));
            q.front()->left = child;
            q.push(child);
        }
        temp = "";
        while (serialized[i] != ' ')
        {
            temp.push_back(serialized[i]);
            i++;
        }
        i++;
        if (temp != "-1")
        {
            TreeNode<int> *child = new TreeNode<int>(stoi(temp));
            q.front()->right = child;
            q.push(child);
        }
        q.pop();
    }

    return root;
}
