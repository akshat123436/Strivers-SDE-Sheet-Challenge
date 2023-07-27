#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> distances(n + 1, 1e9);
    distances[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &a : edges)
        {
            int v1 = a[0];
            int v2 = a[1];
            int w = a[2];

            if (distances[v1] != 1e9 && distances[v1] + w < distances[v2])
            {
                distances[v2] = distances[v1] + w;
            }
        }
    }

    return distances[dest];
}