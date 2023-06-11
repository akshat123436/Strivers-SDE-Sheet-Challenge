#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    map<int, int> count;
    int n = arr.size();
    vector<int> ans;
    for (auto a : arr)
    {
        count[a]++;
        if (count[a] == n / 3 + 1)
        {
            ans.push_back(a);
        }
    }

    return ans;
}