#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    vector<int> dis(vertices, INT_MAX);

    dis[0] = 0;

    vector<vector<pair<int, int>>> graph(vertices);

    for (auto &a : vec)
    {
        graph[a[1]].push_back({a[0], a[2]});
        graph[a[0]].push_back({a[1], a[2]});
    }

    set<pair<int, int>> s;

    s.insert({0, 0});

    while (s.size())
    {
        auto p = *(s.begin());
        s.erase(s.begin());
        int distance = p.first;
        int node = p.second;

        for (auto a : graph[node])
        {
            int value = distance + a.second;
            int child = a.first;
            if (dis[child] > value)
            {
                s.erase({dis[child], child});
                dis[child] = value;
                s.insert({value, child});
            }
        }
    }

    return dis;
}
