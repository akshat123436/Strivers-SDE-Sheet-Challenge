#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n = intervals.size();
    vector<pair<int, int>> paired(n), ans;

    for (int i = 0; i < n; i++)
    {
        paired[i] = {intervals[i][0], intervals[i][1]};
    }

    sort(paired.begin(), paired.end());

    int ptr = 1;
    int start = paired[0].first, end = paired[0].second;
    while (ptr < n)
    {
        if (paired[ptr].first <= end)
        {
            end = max(end, paired[ptr].second);
            ptr++;
        }
        else
        {
            ans.push_back({start, end});
            start = paired[ptr].first;
            end = paired[ptr].second;
        }
    }
    ans.push_back({start, end});
    vector<vector<int>> anspattern;
    for (auto a : ans)
    {
        anspattern.push_back({a.first, a.second});
    }

    return anspattern;
}
