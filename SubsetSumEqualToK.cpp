#include <bits/stdc++.h>
int f(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (k)
            return 0;
        else
            return 1;
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    // pick
    int pick = 0;
    if (arr[i] <= k)
    {
        pick = f(i + 1, n, k - arr[i], arr, dp);
    }
    // notPick
    int notPick = f(i + 1, n, k, arr, dp);

    return dp[i][k] = pick | notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return f(0, n, k, arr, dp);
}