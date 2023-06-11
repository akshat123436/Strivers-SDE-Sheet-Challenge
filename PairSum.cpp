#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    map<int, int> count;
    vector<vector<int>> ans;
    for (auto a : arr)
        count[a]++;

    for (auto a : arr)
    {
        int num = s - a;
        if (num == a)
        {
            int temp = count[a] - 1;
            count[a]--;
            for (int i = 0; i < temp; i++)
            {
                ans.push_back({a, num});
            }
        }
        else if (num > a)
        {
            for (int i = 0; i < count[num]; i++)
            {
                ans.push_back({a, num});
            }
        }
    }

    return ans;
}