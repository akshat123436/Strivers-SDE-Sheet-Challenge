#include <bits/stdc++.h>

bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    return a.first > b.first;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    // value ^ ---- for the given weight allowed
    // break the items into parts
    // prefer the items with higher value/weight------ 1 - 10, 1 - 12....i prefer 1-12
    // I have limited amount of weight of each item, so i'll take miminum of the weight remaining in the knapsack and maximum weight remaining for the items under consideration

    vector<pair<double, int>> valuePerWeight;

    for (auto a : items)
    {
        valuePerWeight.push_back({double(a.second) / a.first, a.first});
    }

    sort(valuePerWeight.begin(), valuePerWeight.end(), cmp);

    double ans = 0;

    for (auto a : valuePerWeight)
    {
        int possibleToTake = min(a.second, w);
        ans += a.first * possibleToTake;
        w -= possibleToTake;
    }

    return ans;
}