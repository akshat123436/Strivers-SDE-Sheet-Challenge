#include <bits/stdc++.h>

int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m)
{
    // cout << i << " " << j << " " << n << " " << m <<  endl;
    if (i >= n || j >= m)
    {
        return 1e9;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = minSum(i, j + 1, grid, dp, n, m);
    int bottom = minSum(i + 1, j, grid, dp, n, m);
    // cout << i << " " << j << " " << right << " " << bottom << endl;
    return dp[i][j] = grid[i][j] + min(right, bottom);
}

int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[n - 1][m - 1] = grid[n - 1][m - 1];
    minSum(0, 0, grid, dp, n, m);
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[0][0];
}