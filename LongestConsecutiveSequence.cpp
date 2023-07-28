#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> doesExists;
    for (int i = 0; i < n; i++)
        doesExists.insert(arr[i]);

    int ans = 1;

    int count = 1;

    for (int i = 0; i < n; i++)
    {
        if (doesExists.find(arr[i] - 1) == doesExists.end())
        {
            int num = arr[i] + 1;
            while (doesExists.find(num) != doesExists.end())
            {
                count++;
                num++;
            }
            ans = max(ans, count);
            count = 1;
        }
    }

    return ans;
}