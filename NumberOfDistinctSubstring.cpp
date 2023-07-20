#include <bits/stdc++.h>
struct Node
{
    Node *chars[26];
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &s, int &count)
    {
        Node *cur = root;

        for (auto a : s)
        {
            Node *temp = cur->chars[a % 26];
            if (temp)
            {
                cur = temp;
            }
            else
            {
                count++;
                temp = new Node();
                cur->chars[a % 26] = temp;
                cur = temp;
            }
        }
    }
};
int distinctSubstring(string &word)
{
    //  Write your code here.
    Trie t;
    int n = word.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string s = word.substr(i, j - i + 1);
            t.insert(s, ans);
        }
    }

    return ans;
}
