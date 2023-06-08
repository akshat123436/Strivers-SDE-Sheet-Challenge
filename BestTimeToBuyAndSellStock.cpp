#include <bits/stdc++.h>

int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int profit = 0;

    int low = prices[0];
    int high = low;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > high)
        {
            high = prices[i];
            profit = max(profit, high - low);
        }
        if (prices[i] < low)
        {
            low = prices[i];
            high = prices[i];
        }
    }
    return profit;
}