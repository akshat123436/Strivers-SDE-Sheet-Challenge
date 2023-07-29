#include <bits/stdc++.h>
int heightOfTheTree(vector<int> &inorder, vector<int> &levelOrder, int N)
{
    queue<vector<int>> q;
    q.push({0, 0, N - 1});
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[inorder[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto a = q.front();
        q.pop();

        int l = a[1];
        int r = a[2];
        int h = a[0];
        int curIndex = mp[levelOrder[i]];
        ans = max(ans, h);
        if (l < curIndex)
        {
            q.push({h + 1, l, curIndex - 1});
        }
        if (r > curIndex)
        {
            q.push({h + 1, curIndex + 1, r});
        }
    }
    return ans;
}