int f(vector<vector<int>> &dp, vector<int> &values, vector<int> &weights, int n, int w, int i)
{
    if (i >= n)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];
    int val = 0;
    if (weights[i] <= w)
        val = values[i] + f(dp, values, weights, n, w - weights[i], i + 1);
    val = max(val, f(dp, values, weights, n, w, i + 1));

    return dp[i][w] = val;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    return f(dp, values, weights, n, w, 0);
}