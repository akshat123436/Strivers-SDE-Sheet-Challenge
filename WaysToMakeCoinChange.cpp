#include <vector>

long f(int index, int value, int *denominations, int n, vector<vector<long>> &dp)
{
    if (value == 0)
        return 1;
    if (index == n)
        return 0;
    if (dp[index][value] != -1)
        return dp[index][value];
    long ways = 0;
    for (int i = 0; i <= value / denominations[index]; i++)
    {
        ways += f(index + 1, value - (i * denominations[index]), denominations, n, dp);
    }

    return dp[index][value] = ways;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(0, value, denominations, n, dp);
}