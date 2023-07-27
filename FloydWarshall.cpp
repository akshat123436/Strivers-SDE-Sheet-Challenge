int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> distances(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++)
        distances[i][i] = 0;
    for (auto &a : edges)
    {
        distances[a[0]][a[1]] = a[2];
    }
    for (int via = 1; via <= n; via++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (distances[i][via] != 1e9 && distances[via][j] != 1e9 && distances[i][via] + distances[via][j] < distances[i][j])
                {
                    distances[i][j] = distances[i][via] + distances[via][j];
                }
            }
        }
    }

    return distances[src][dest];
}