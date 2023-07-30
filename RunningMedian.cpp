#include <queue>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // cout << 1 << endl;
    for (int i = 0; i < n; i++)
    {
        // cout << maxHeap.size() << endl;
        if (maxHeap.size() <= minHeap.size())
        {
            maxHeap.push(arr[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else
        {
            maxHeap.push(arr[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // cout << maxHeap.top() << " " << ((minHeap.size()) ? minHeap.top() : 0) << endl;
        // cout << maxHeap.size() << " " << minHeap.size() << endl;
        if (maxHeap.size() == minHeap.size())
            (arr[i] = (maxHeap.top() + minHeap.top()) / 2);
        else
            (arr[i] = maxHeap.top());
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}