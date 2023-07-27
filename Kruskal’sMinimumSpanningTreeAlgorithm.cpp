#include <bits/stdc++.h>
class disjointSet
{
private:
    vector<int> parent, size;

public:
    disjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void setUnion(int first, int second)
    {
        int firstUltimateParent = findUltimateParent(first);
        int secondUltimateParent = findUltimateParent(second);

        if (firstUltimateParent == secondUltimateParent)
            return;

        if (size[firstUltimateParent] > size[secondUltimateParent])
        {
            parent[secondUltimateParent] = firstUltimateParent;
            size[firstUltimateParent] += size[secondUltimateParent];
        }
        else
        {
            parent[firstUltimateParent] = secondUltimateParent;
            size[secondUltimateParent] += size[firstUltimateParent];
        }
    }
};
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    // Write your code here.
    disjointSet dj(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    for (auto &a : graph)
    {
        q.push({a[2], {a[0], a[1]}});
    }
    int ans = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int w = t.first;
        int first = t.second.first;
        int second = t.second.second;
        q.pop();
        if (dj.findUltimateParent(first) != dj.findUltimateParent(second))
        {
            ans += w;
            dj.setUnion(first, second);
        }
    }

    return ans;
}