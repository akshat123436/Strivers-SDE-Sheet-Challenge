#include <bits/stdc++.h>

int rec(int n, int k, vector<vector<int>> &dp)

{

    if (n <= 0 || k <= 0)
        return 0;

    if (k == 1)
        return n;

    if (n == 1)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int ans = INT_MAX;

    int low = 1;

    int high = n;

    while (low <= high)

    {

        int mid = low + (high - low) / 2;

        int broken = rec(mid - 1, k - 1, dp);

        int notBroken = rec(n - mid, k, dp);

        int result = max(notBroken, broken);

        ans = min(result + 1, ans);

        if (broken < notBroken)

        {

            low = mid + 1;
        }

        else
        {

            high = mid - 1;
        }
    }

    return dp[n][k] = ans;
}
int cutLogs(int k, int n)
{
    // Write your code here.
    // int dp[k+1][n+1];
    // for(int i = 0;i<=k;i++){
    //     for(int j = 0;j<=n;j++){
    //         dp[i][j] = j;
    //     }
    // }

    // for(int i = 2;i<=k;i++){
    //     for(int j = 2;j<=n;j++){
    //         for(int t = 1;t<=j;t++){
    //             int currentComparisons = max(dp[i-1][t-1], dp[i][j-t]);
    //             dp[i][j] = min(dp[i][j], currentComparisons);
    //         }
    //         dp[i][j]++;
    //     }
    // }

    // return dp[k][n];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return rec(n, k, dp);
}
