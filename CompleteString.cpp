#include <bits/stdc++.h>
struct Node
{
    Node *chars[26];
    bool end;
    Node()
    {
        for (int i = 0; i < 26; i++)
            chars[i] = nullptr;
        end = false;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &s)
    {
        Node *current = root;

        for (auto a : s)
        {
            Node *temp = current->chars[a % 26];
            if (temp)
            {
                current = temp;
            }
            else
            {
                temp = new Node();
                current->chars[a % 26] = temp;
                current = temp;
            }
        }
        current->end = true;
    }

    bool isComplete(string &s)
    {
        Node *current = root;

        for (auto a : s)
        {
            Node *temp = current->chars[a % 26];

            if (!temp)
                return false;
            if (!temp->end)
                return false;
            current = temp;
        }

        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    string ans;

    Trie t;

    for (auto &s : a)
    {
        t.insert(s);
    }

    for (auto &s : a)
    {
        if (t.isComplete(s))
        {
            if (s.length() > ans.length())
            {
                ans = s;
            }
            else if (s.length() == ans.length())
            {
                if (s < ans)
                    ans = s;
            }
        }
    }
    if (ans.size())
        return ans;
    return "None";
}