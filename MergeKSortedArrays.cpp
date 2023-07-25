#include <bits/stdc++.h>
vector<int> merge(vector<int> &first, vector<int> &second)
{
    int n = first.size();
    int m = second.size();
    vector<int> ans(n + m);
    int f = 0, s = 0, a = 0;

    while (f < n && s < m)
    {
        if (first[f] < second[s])
        {
            ans[a++] = first[f++];
        }
        else
        {
            ans[a++] = second[s++];
        }
    }

    while (f < n)
    {
        ans[a++] = first[f++];
    }
    while (s < m)
    {
        ans[a++] = second[s++];
    }

    return ans;
}
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    // int n = 0;

    // for(auto &a : kArrays) n+=a.size();

    vector<int> ans;
    for (auto &a : kArrays)
    {
        ans = merge(a, ans);
    }

    return ans;
}
