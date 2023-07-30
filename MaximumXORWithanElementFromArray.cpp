#include <bits/stdc++.h>
struct Node
{
    Node *one;
    Node *zero;

    Node()
    {
        one = nullptr;
        zero = nullptr;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *temp = root;

        long long check = 1LL << 33;

        while (check)
        {
            long long bit = check & num;
            if (bit)
            {
                if (temp->one)
                {
                    temp = temp->one;
                }
                else
                {
                    temp->one = new Node();
                    temp = temp->one;
                }
            }
            else
            {
                if (temp->zero)
                {
                    temp = temp->zero;
                }
                else
                {
                    temp->zero = new Node();
                    temp = temp->zero;
                }
            }
            check >>= 1;
        }
    }

    int findXor(int num)
    {
        // cout << num << endl;
        long long check = 1LL << 33;

        long long ans = 0;
        Node *temp = root;
        int i = 0;
        while (check)
        {
            long long bit = check & num;
            // cout << check << endl;
            // cout << ans << endl;
            if (bit)
            {
                if (temp->zero)
                {
                    ans += check;
                    temp = temp->zero;
                }
                else if (temp->one)
                {
                    temp = temp->one;
                }
                else
                    return -1;
            }
            else
            {
                if (temp->one)
                {
                    ans += check;
                    temp = temp->one;
                }
                else if (temp->zero)
                {
                    temp = temp->zero;
                }
                else
                    return -1;
            }
            check >>= 1;
        }
        return ans;
    }
};

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] < b[1])
        return true;
    return false;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());

    for (int i = 0; i < queries.size(); i++)
    {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), cmp);
    int n = arr.size();
    Trie *t = new Trie();
    int i = 0;
    vector<int> ans(queries.size());
    for (auto &a : queries)
    {
        while (i < n && arr[i] <= a[1])
        {
            t->insert(arr[i]);
            i++;
        }
        ans[a[2]] = t->findXor(a[0]);
    }
    return ans;
}