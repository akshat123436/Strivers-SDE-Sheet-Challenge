#include <vector>

int f(int i, int j, string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + f(i + 1, j + 1, s, t, n, m, dp);
    return dp[i][j] = max(f(i + 1, j, s, t, n, m, dp), f(i, j + 1, s, t, n, m, dp));
}

int lcs(string s, string t)
{
    // Write your code here
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return f(0, 0, s, t, n, m, dp);
}