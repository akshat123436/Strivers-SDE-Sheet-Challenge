int maxCost(vector<int> &price, int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int maxVal = price[n - 1];

    for (int i = 1; i <= n / 2; i++)
    {
        maxVal = max(maxVal, maxCost(price, i, dp) + maxCost(price, n - i, dp));
    }

    return dp[n] = maxVal;
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return maxCost(price, n, dp);
}
