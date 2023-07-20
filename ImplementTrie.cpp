/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node
{
    Node *characters[26];
    bool isEnd;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            characters[i] = nullptr;
        }
        isEnd = false;
    }
};
class Trie
{
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
        root->isEnd = true;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *current = root;

        for (auto a : word)
        {
            Node *temp = current->characters[a % 26];
            if (temp)
            {
                current = temp;
            }
            else
            {
                temp = new Node();
                current->characters[a % 26] = temp;
                current = temp;
            }
        }
        current->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *current = root;

        for (auto a : word)
        {
            Node *temp = current->characters[a % 26];
            if (!temp)
                return false;
            current = temp;
        }
        if (current->isEnd)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *current = root;
        for (auto a : prefix)
        {
            Node *temp = current->characters[a % 26];
            if (!temp)
                return false;
            current = temp;
        }

        return true;
    }
};