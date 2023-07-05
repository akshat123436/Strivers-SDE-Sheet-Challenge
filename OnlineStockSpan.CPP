#include <bits/stdc++.h>
int f(vector<int> &ans, int index, vector<int> &price, int val)
{
    if (index < 0)
        return 0;
    if (price[index] > val)
        return 0;
    return ans[index] + f(ans, index - ans[index], price, val);
}
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();

    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans[i] = 1 + f(ans, i - 1, price, price[i]);
    }
    return ans;
}