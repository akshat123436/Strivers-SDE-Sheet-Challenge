#include <bits/stdc++.h>

void f(int n, vector<int> &arr, vector<vector<int>> &ans, int i, vector<int> &ds, map<int, int> &dontPick)
{
    // cout << i << " " << n << endl;
    if (i == n)
    {
        ans.push_back(ds);
        return;
    }

    // pick
    if (!dontPick[arr[i]])
    {
        ds.push_back(arr[i]);
        f(n, arr, ans, i + 1, ds, dontPick);
        ds.pop_back();
    }

    // notpick
    dontPick[arr[i]]++;
    f(n, arr, ans, i + 1, ds, dontPick);
    dontPick[arr[i]]--;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    map<int, int> dontPick;
    sort(arr.begin(), arr.end());
    f(n, arr, ans, 0, ds, dontPick);
    sort(ans.begin(), ans.end());
    return ans;
}