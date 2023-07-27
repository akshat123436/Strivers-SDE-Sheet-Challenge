#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (auto &a : g)
    {
        graph[a.first.first].push_back({a.first.second, a.second});
        graph[a.first.second].push_back({a.first.first, a.second});
    }

    q.push({0, {1, 0}});
    vector<bool> vis(n + 1);
    vis[0] = true;
    vector<pair<pair<int, int>, int>> ans;
    while (!q.empty())
    {
        auto f = q.top();
        q.pop();
        int w = f.first;
        int node = f.second.first;
        int parent = f.second.second;

        if (!vis[node] && parent)
            ans.push_back({{node, parent}, w});
        vis[node] = true;
        for (auto &a : graph[node])
        {
            if (!vis[a.first])
            {
                q.push({a.second, {a.first, node}});
            }
        }
    }

    return ans;
}
