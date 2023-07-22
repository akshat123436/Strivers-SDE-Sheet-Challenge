#include <queue>
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<bool> vis(n + 1, false);

    vector<vector<int>> graph(n + 1);

    for (auto a : edges)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<pair<int, int>> nodes;
            nodes.push({i, -1});

            while (!nodes.empty())
            {
                int cur = nodes.front().first;
                int parent = nodes.front().second;
                nodes.pop();
                vis[cur] = true;

                for (auto a : graph[cur])
                {
                    if (vis[a] && a != parent)
                    {
                        found = true;
                        break;
                    }
                    else if (!vis[a])
                    {
                        nodes.push({a, cur});
                    }
                }
                if (found)
                    break;
            }
        }
        if (found)
            break;
    }

    if (found)
        return "Yes";
    return "No";
}
