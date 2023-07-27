#include <stack>

void dfs(stack<int> &finishingTime, vector<vector<int>> &graph, vector<bool> &vis, int node)
{
    if (vis[node])
        return;
    vis[node] = true;

    for (auto a : graph[node])
    {
        dfs(finishingTime, graph, vis, a);
    }
    finishingTime.push(node);
}
void dfs2(vector<int> &cmpNodes, vector<vector<int>> &graph, vector<bool> &vis, int node)
{
    if (vis[node])
        return;
    vis[node] = true;
    cmpNodes.push_back(node);
    for (auto a : graph[node])
    {
        dfs2(cmpNodes, graph, vis, a);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    stack<int> finishingTime;

    vector<vector<int>> graph(n), reversedGraph(n);

    for (auto &a : edges)
    {
        graph[a[0]].push_back(a[1]);
    }
    for (auto &a : edges)
    {
        reversedGraph[a[1]].push_back(a[0]);
    }
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        dfs(finishingTime, graph, vis, i);

    for (int i = 0; i < n; i++)
        vis[i] = false;
    vector<vector<int>> ans;
    while (finishingTime.size())
    {
        int cur = finishingTime.top();
        finishingTime.pop();
        if (!vis[cur])
        {
            vector<int> cmpNodes;
            dfs2(cmpNodes, reversedGraph, vis, cur);
            ans.push_back(cmpNodes);
        }
    }

    return ans;
}