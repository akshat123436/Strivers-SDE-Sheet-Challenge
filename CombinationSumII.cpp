#include <bits/stdc++.h>
void f(vector<int> &arr, int n, int target, int index, vector<pair<int, int>> &ds, vector<vector<int>> &ans)
{
    if (index == n)
    {
        if (!target)
        {
            vector<int> temp;
            for (auto &a : ds)
                temp.push_back(a.first);
            ans.push_back(temp);
        }

        return;
    }

    // pick
    if (index)
    {
        if (arr[index] == arr[index - 1] && (ds[ds.size() - 1].second != index - 1 || !ds.size()))
        {
        }
        else
        {
            if (arr[index] <= target)
            {
                ds.push_back({arr[index], index});
                f(arr, n, target - arr[index], index + 1, ds, ans);
                ds.pop_back();
            }
        }
    }
    else
    {
        if (arr[index] <= target)
        {
            ds.push_back({arr[index], index});
            f(arr, n, target - arr[index], index + 1, ds, ans);
            ds.pop_back();
        }
    }

    // notpick
    f(arr, n, target, index + 1, ds, ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<pair<int, int>> ds;
    f(arr, n, target, 0, ds, ans);
    return ans;
}
