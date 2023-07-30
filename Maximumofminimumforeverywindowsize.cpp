#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    stack<pair<int, int>> s;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().first >= a[i])
        {
            s.pop();
        }
        if (s.empty())
            left[i] = -1;
        else
        {
            left[i] = s.top().second;
        }
        s.push({a[i], i});
    }

    stack<pair<int, int>> t;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!t.empty() && t.top().first >= a[i])
        {
            t.pop();
        }
        if (t.empty())
            right[i] = n;
        else
        {
            right[i] = t.top().second;
        }
        t.push({a[i], i});
    }
    vector<int> maxWindowSize(n);

    for (int i = 0; i < n; i++)
    {
        maxWindowSize[i] = i - left[i] + right[i] - i - 1;
    }
    vector<int> ans(n, -1e9 - 1);
    // for(int i = 0;i<n;i++) cout << maxWindowSize[i] << endl;
    for (int i = 0; i < n; i++)
    {
        ans[maxWindowSize[i] - 1] = max(ans[maxWindowSize[i] - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}