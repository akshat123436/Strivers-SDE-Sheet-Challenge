#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    vector<long> leftHeight(n), rightHeight(n);

    leftHeight[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        leftHeight[i] = max(leftHeight[i - 1], arr[i]);
    }
    rightHeight[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightHeight[i] = max(rightHeight[i + 1], arr[i]);
    }
    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long val = min(leftHeight[i], rightHeight[i]) - arr[i];

        if (val >= 0)
            ans += val;
    }

    return ans;
}