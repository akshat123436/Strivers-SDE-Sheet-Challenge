#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> ans(n);

    stack<int> nextElement;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!nextElement.empty() && nextElement.top() <= arr[i])
            nextElement.pop();
        if (nextElement.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = nextElement.top();
        }
        nextElement.push(arr[i]);
    }
    return ans;
}