#include <bits/stdc++.h>

bool isPalindrome(string &s)
{
    int start = 0, end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }

    return true;
}

void f(int i, string &s, vector<vector<string>> &ans, vector<string> &ds)
{
    if (i == s.length())
    {
        ans.push_back(ds);
        return;
    }
    string temp;
    for (int j = i; j < s.length(); j++)
    {
        temp.push_back(s[j]);

        if (isPalindrome(temp))
        {
            ds.push_back(temp);
            f(j + 1, s, ans, ds);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> ds;
    f(0, s, ans, ds);

    return ans;
}