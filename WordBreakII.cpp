#include <bits/stdc++.h>

void f(string &s, vector<string> &ds, vector<string> &ans, int n, unordered_map<string, bool> &isValid, int index)
{
    if (index == n)
    {
        string temp;
        for (int i = 0; i < ds.size(); i++)
        {
            temp += ds[i];
            temp.push_back(' ');
        }
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    string temp;
    for (int i = index; i < n; i++)
    {
        temp.push_back(s[i]);
        if (isValid[temp])
        {
            ds.push_back(temp);
            f(s, ds, ans, n, isValid, i + 1);
            ds.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string, bool> isValid;

    for (auto &a : dictionary)
        isValid[a] = true;

    vector<string> ans;
    vector<string> ds;
    int n = s.length();
    f(s, ds, ans, n, isValid, 0);

    return ans;
}