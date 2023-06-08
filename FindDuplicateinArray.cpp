#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        int num = abs(arr[i]);
        if (arr[num - 1] < 0)
            return num;
        else
            arr[num - 1] = -arr[num - 1];
    }
    return arr[n - 1];
}
