#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j || j == i)
            {
                ans[i].push_back(1);
            }
            else
            {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
        }
    }

    return ans;
}
