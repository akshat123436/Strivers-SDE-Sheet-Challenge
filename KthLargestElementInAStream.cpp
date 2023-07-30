#include <algorithm>

class Kthlargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    int current;
    int kth;

public:
    Kthlargest(int k, vector<int> &arr)
    {
        for (auto &a : arr)
            pq.push(a);
    }

    int add(int num)
    {
        if (num > pq.top())
        {
            pq.pop();
            pq.push(num);
        }
        return pq.top();
    }
};