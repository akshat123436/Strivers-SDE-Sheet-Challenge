#include <bits/stdc++.h>
struct Node
{
    Node *bit[2];
    Node()
    {
        bit[0] = nullptr;
        bit[1] = nullptr;
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

    void insert(int num)
    {
        Node *cur = root;
        int check = 1 << 30;
        while (check)
        {
            int n = num & check;
            if (n)
                n = 1;
            Node *temp = (cur->bit)[n];
            if (temp)
            {
                cur = temp;
            }
            else
            {
                temp = new Node();
                cur->bit[n] = temp;
                cur = temp;
            }
            check >>= 1;
        }
    }

    int maxXorFinder(int num)
    {
        int check = 1 << 30;
        int val = 0;
        Node *cur = root;
        while (check)
        {
            int n = num & check;
            // cout<< num << " " << n << endl;
            int req = 0;
            if (n)
                req = 0;
            else
                req = 1;
            Node *temp = cur->bit[req];
            if (temp)
            {
                val += check;
                cur = temp;
            }
            else
            {
                if (req)
                    req = 0;
                else
                    req = 1;

                if (cur->bit[req])
                {
                    cur = cur->bit[req];
                }
                else
                {
                    return val;
                }
            }
            check >>= 1;
        }

        return val;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie t;
    for (auto a : A)
    {
        t.insert(a);
    }

    int ans = 0;

    for (auto a : A)
    {
        ans = max(ans, t.maxXorFinder(a));
    }
    return ans;
}