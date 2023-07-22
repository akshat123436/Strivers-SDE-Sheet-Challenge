#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> graph(vertex);

    for (auto a : edges)
    {
        graph[a.first].push_back(a.second);
        graph[a.second].push_back(a.first);
    }
    for (auto &a : graph)
        sort(a.begin(), a.end());
    vector<bool> vis(vertex, false);
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int cur = q.front();
                ans.push_back(cur);
                q.pop();
                for (auto a : graph[cur])
                {
                    if (!vis[a])
                    {
                        vis[a] = true;
                        q.push(a);
                    }
                }
            }
        }
    }
    return ans;
}