#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (maxHeap.size() <= minHeap.size())
        {
            minHeap.push(arr[i]);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else
        {
            maxHeap.push(arr[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() == minHeap.size())
        {
            ans.push_back((maxHeap.top() + minHeap.top()) / 2);
        }
        else
        {
            ans.push_back(maxHeap.top());
        }
    }

    return ans;
}
