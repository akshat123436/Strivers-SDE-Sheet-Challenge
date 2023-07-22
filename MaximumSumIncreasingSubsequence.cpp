#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    int ans = 0;
    vector<int> dp = rack;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (rack[j] > rack[i])
                dp[i] = max(dp[i], rack[i] + dp[j]);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}