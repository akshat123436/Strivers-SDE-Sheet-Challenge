#include <bits/stdc++.h>
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[m - 1][n - 1] = 1;
    for (int i = 0; i < n + 1; i++)
    {
        dp[m][i] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][n] = 0;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // cout <<
            if (!(i == m - 1 && j == n - 1))
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
    // dp[n-1][n-1]
    // dp[0][0]
}