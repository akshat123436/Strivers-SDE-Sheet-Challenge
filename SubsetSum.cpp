#include <bits/stdc++.h>
void findSubset(vector<int> &num, vector<int> &ans, int sum, int &n, int i)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }

    // pick
    findSubset(num, ans, sum + num[i], n, i + 1);
    // notpick
    findSubset(num, ans, sum, n, i + 1);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n = num.size();
    findSubset(num, ans, 0, n, 0);
    sort(ans.begin(), ans.end());

    return ans;
}