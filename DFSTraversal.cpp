void findDfs(vector<int> &dfs, int node, vector<vector<int>> &graph, vector<bool> &vis)
{
    if (vis[node])
        return;
    vis[node] = true;
    dfs.push_back(node);
    for (auto a : graph[node])
    {
        findDfs(dfs, a, graph, vis);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<bool> vis(V, false);
    vector<vector<int>> ans;
    vector<vector<int>> graph(V);

    for (auto &a : edges)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> dfs;
            findDfs(dfs, i, graph, vis);
            ans.push_back(dfs);
        }
    }

    return ans;
}