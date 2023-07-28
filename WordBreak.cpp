#include <bits/stdc++.h>
int isPossible(string &target, int n, unordered_map<string, bool> &isValid, int i, vector<int> &dp)
{
    if (i == n)
    {
        return true;
    }
    if (dp[i] != -1)
        return dp[i];
    string temp;
    int check = 0;
    for (int k = i; k < n; k++)
    {
        temp.push_back(target[k]);
        if (isValid[temp])
        {
            check += isPossible(target, n, isValid, k + 1, dp);
        }
    }
    if (check)
        return dp[i] = 1;
    return dp[i] = 0;
}

bool wordBreak(vector<string> &arr, int n, string &target)
{
    unordered_map<string, bool> isValid;
    for (auto &a : arr)
    {
        isValid[a] = true;
    }
    vector<int> dp(target.size(), -1);
    return bool(isPossible(target, target.size(), isValid, 0, dp));
}