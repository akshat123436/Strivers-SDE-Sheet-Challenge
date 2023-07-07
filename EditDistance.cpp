int f(int i, int j, string &one, string &two, vector<vector<int>> &dp, int n, int m)
{
    if (i >= n && j >= m)
        return 0;
    if (i >= n)
        return m - j;
    if (j >= m)
        return n - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minOp = 10e7;
    if (one[i] == two[j])
    {
        minOp = f(i + 1, j + 1, one, two, dp, n, m);
    }
    else
    {
        minOp = min(f(i + 1, j, one, two, dp, n, m), f(i, j + 1, one, two, dp, n, m));
        minOp = min(minOp, f(i + 1, j + 1, one, two, dp, n, m));
        minOp += 1;
    }

    return dp[i][j] = minOp;
}

int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(0, 0, str1, str2, dp, n, m);
}