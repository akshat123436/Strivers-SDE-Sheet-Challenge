#include <bits/stdc++.h>
void merge(int start1, int end1, int start2, int end2, long long *arr, int &ans)
{
    // cout << start1 << " " << end1 << " " << start2 << " " << end2 << endl;
    vector<int> v(end2 - start1 + 1);
    int ptr = 0;
    int s = start1, e = end2;
    while (start1 <= end1 && start2 <= end2)
    {
        if (arr[start1] > arr[start2])
        {
            ans += end1 - start1 + 1;
            v[ptr] = arr[start2];
            start2++;
        }
        else
        {
            v[ptr] = arr[start1];
            start1++;
        }
        ptr++;
    }

    while (start1 <= end1)
    {
        v[ptr] = arr[start1];
        start1++;
        ptr++;
    }

    while (start2 <= end2)
    {
        v[ptr] = arr[start2];
        start2++;
        ptr++;
    }
    ptr = 0;

    for (int i = s; i <= e; i++)
    {
        arr[i] = v[ptr];
        ptr++;
    }
}
void mergeSort(int start, int end, long long *arr, int &ans)
{
    // cout << start << " " << end << endl;
    if (start >= end)
        return;
    mergeSort(start, (start + end) / 2, arr, ans);
    mergeSort((start + end) / 2 + 1, end, arr, ans);

    merge(start, (start + end) / 2, (start + end) / 2 + 1, end, arr, ans);
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.

    int ans = 0;

    mergeSort(0, n - 1, arr, ans);
    return ans;
}