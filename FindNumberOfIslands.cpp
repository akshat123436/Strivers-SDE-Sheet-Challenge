void dfs(int i, int j, vector<vector<int>> &arr2, vector<vector<bool>> &vis, int n, int m, int *dlr, int *dlc)
{
    if (vis[i][j] || !arr2[i][j])
        return;
    vis[i][j] = true;

    for (int t = 0; t < 8; t++)
    {
        int adjr = i + dlr[t];
        int adjc = j + dlc[t];
        if (adjc >= 0 && adjr >= 0 && adjc < m && adjr < n)
        {
            dfs(adjr, adjc, arr2, vis, n, m, dlr, dlc);
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> arr2(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    int dlr[] = {-1, -1, -1, +1, +1, +1, 0, 0};
    int dlc[] = {0, -1, 1, -1, 0, +1, 1, -1};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] && !vis[i][j])
            {
                ans++;
                dfs(i, j, arr2, vis, n, m, dlr, dlc);
            }
        }
    }

    return ans;
}
