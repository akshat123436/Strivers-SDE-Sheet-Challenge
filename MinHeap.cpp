#include <bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> ans;
    for (auto &a : q)
    {
        if (a[0])
        {
            ans.push_back(heap.top());
            heap.pop();
        }
        else
        {
            heap.push(a[1]);
        }
    }

    return ans;
}
