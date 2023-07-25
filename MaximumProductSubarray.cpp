#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int prefix = 1;
    int suffix = 1;
    int ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        prefix *= arr[i];

        ans = max(ans, prefix);

        if (!prefix)
            prefix = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suffix *= arr[i];

        ans = max(ans, suffix);

        if (!suffix)
            suffix = 1;
    }
    return ans;
}
