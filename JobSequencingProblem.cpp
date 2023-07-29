#include <bits/stdc++.h>
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    priority_queue<int> p;

    unordered_map<int, vector<int>> mp;

    int mx = 0;

    for (int i = 0; i < jobs.size(); i++)
    {

        mx = max(mx, jobs[i][1]);

        mp[jobs[i][1]].push_back(jobs[i][2]);
    }

    int ans = 0, c = 0;

    for (int i = mx; i > 0; i--)
    {

        for (auto &q : mp[i])
        {

            p.push(q);
        }

        if (p.size() == 0)
        {

            continue;
        }
        c++;
        ans += p.top();

        p.pop();
    }

    return {c, ans};
}