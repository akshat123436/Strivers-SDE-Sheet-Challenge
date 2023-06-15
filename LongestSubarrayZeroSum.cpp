#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here

    unordered_map<int, int> sumMaxIndex;
    int n = arr.size();
    vector<int> temp(n + 1);
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        temp[i] = arr[i - 1] + temp[i - 1];
        sumMaxIndex[temp[i]] = i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        ans = max(ans, sumMaxIndex[temp[i]] - i);
    }
    return ans;
}