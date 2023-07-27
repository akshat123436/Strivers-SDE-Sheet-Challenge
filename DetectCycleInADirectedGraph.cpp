#include <queue>
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<vector<int>> children(n + 1);
    vector<int> indegree(n + 1);
    for (auto a : edges)
    {
        children[a.first].push_back(a.second);
        indegree[a.second]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    int count = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        count++;
        for (auto a : children[cur])
        {
            indegree[a]--;
            if (!indegree[a])
                q.push(a);
        }
    }

    if (count == n)
        return false;
    return true;
}