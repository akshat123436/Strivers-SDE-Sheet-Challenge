#include <bits/stdc++.h>
int kthLargest(vector<int> &arr, int size, int K)
{
    priority_queue<int> q;

    for (int i = 0; i < size; i++)
        q.push(arr[i]);

    for (int i = 0; i < K - 1; i++)
        q.pop();

    return q.top();
}