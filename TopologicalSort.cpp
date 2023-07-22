#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> ans;

    vector<int> indegree(v);
    vector<vector<int>> graph(v);
    for (auto &a : edges)
    {
        indegree[a[1]]++;
        graph[a[0]].push_back(a[1]);
    }
    queue<int> nodes;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            nodes.push(i);
    }

    while (!nodes.empty())
    {
        int cur = nodes.front();
        nodes.pop();
        ans.push_back(cur);
        for (auto a : graph[cur])
        {
            indegree[a]--;
            if (!indegree[a])
                nodes.push(a);
        }
    }

    return ans;
}