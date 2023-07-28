#include <bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    vector<pair<int, int>> sortedOnes;

    for (int i = 0; i < n; i++)
    {
        sortedOnes.push_back({start[i], finish[i]});
    }

    sort(sortedOnes.begin(), sortedOnes.end());
    stack<int> endActivity;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int s = sortedOnes[i].first;
        int e = sortedOnes[i].second;

        if (endActivity.empty())
        {
            endActivity.push(e);
        }
        else
        {
            int lastEnd = endActivity.top();

            if (lastEnd <= s)
            {
                endActivity.push(e);
            }
            else
            {
                endActivity.pop();
                endActivity.push(min(e, lastEnd));
            }
        }

        ans = max(ans, int(endActivity.size()));
    }

    return ans;
}