#include <bits/stdc++.h>

int f(vector<int> &dp, string &str, int n, int i, vector<vector<bool>> &isPalindrome)
{
    if (i == n)
        return 0;
    if (isPalindrome[i][n - 1])
        return dp[i] = 0;
    int count = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome[i][j])
        {
            count = min(count, 1 + f(dp, str, n, j + 1, isPalindrome));
        }
    }

    return dp[i] = count;
}

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, 0));

    for (int i = 0; i < n; i++)
    {
        isPalindrome[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            isPalindrome[i][i + 1] = true;
        }
    }

    for (int stringSize = 3; stringSize <= n; stringSize++)
    {
        for (int i = 0; i + stringSize - 1 < n; i++)
        {
            int j = i + stringSize - 1;
            if (str[i] == str[j] && isPalindrome[i + 1][j - 1])
            {
                isPalindrome[i][j] = true;
            }
        }
    }

    vector<int> dp(n, -1);

    return f(dp, str, n, 0, isPalindrome);
}
