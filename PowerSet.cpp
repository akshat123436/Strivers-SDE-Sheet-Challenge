#include <bits/stdc++.h>
int power(int num, int p)
{
    if (!p)
        return 1;
    int temp = power(num, p / 2);
    if (p & 1)
    {
        return num * temp * temp;
    }
    else
        return temp * temp;
}
vector<vector<int>> pwset(vector<int> v)
{
    // Write your code here
    sort(v.begin(), v.end());
    int n = v.size();
    int val = power(2, n);
    vector<vector<int>> ans;
    for (int i = 0; i < val; i++)
    {
        int num = i;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (num & 1)
                temp.push_back(v[j]);
            num >>= 1;
        }
        ans.push_back(temp);
    }
    return ans;
}