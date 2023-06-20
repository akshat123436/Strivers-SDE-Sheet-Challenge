#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    vector<int> p = arr;
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] ^= arr[i - 1];
    }
    map<int, int> count;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        int val = arr[i] ^ x;

        ans += count[val];
        if (val == arr[i] && p[i] != x)
            ans--;
        if (!val && arr[i])
        {
            ans++;
        }
    }

    return ans;
}