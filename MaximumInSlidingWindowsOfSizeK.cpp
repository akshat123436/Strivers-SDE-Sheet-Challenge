#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> indexes;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        while (!indexes.empty() && nums[indexes.back()] < nums[i])
        {
            indexes.pop_back();
        }

        indexes.push_back(i);
    }
    ans.push_back(nums[indexes.front()]);
    for (int i = k; i < n; i++)
    {
        while (!indexes.empty() && nums[indexes.back()] < nums[i])
        {
            indexes.pop_back();
        }
        indexes.push_back(i);
        while (indexes.front() <= i - k)
            indexes.pop_front();
        ans.push_back(nums[indexes.front()]);
    }

    return ans;
}