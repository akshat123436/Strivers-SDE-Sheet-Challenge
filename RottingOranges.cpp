#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    vector<vector<int>> time(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                time[i][j] = 0;
            }
            else if (grid[i][j] == 2)
            {
                time[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int delr[] = {0, 1, -1, 0};
    int delc[] = {-1, 0, 0, 1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int timeNow = 1 + time[row][col];
        for (int i = 0; i < 4; i++)
        {
            int resr = row + delr[i];
            int resc = col + delc[i];

            if (resr < 0 || resc < 0 || resr >= n || resc >= m)
                continue;

            if (time[resr][resc] > timeNow)
            {
                time[resr][resc] = timeNow;
                q.push({resr, resc});
            }
        }
    }

    int ans = INT_MIN;

    for (auto &a : time)
    {
        for (auto b : a)
        {
            ans = max(ans, b);
        }
    }

    if (ans == 1e9)
        return -1;
    return ans;
}