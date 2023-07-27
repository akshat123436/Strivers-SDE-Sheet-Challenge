#include <queue>

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (edges[i][j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
    }
    vector<int> color(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!color[i])
        {
            color[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                int cur = q.front();
                // cout << cur << endl;

                q.pop();
                int currentColor = color[cur];
                for (auto a : graph[cur])
                {
                    // cout << 1 << a << " " << currentColor << " " << color[a] <<endl;
                    if (!color[a])
                    {
                        if (currentColor == 1)
                            color[a] = 2;
                        else
                            color[a] = 1;
                        q.push(a);
                    }
                    else if (color[a] == currentColor)
                        return false;
                }
            }
        }
    }

    return true;
}