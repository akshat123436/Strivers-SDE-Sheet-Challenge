#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    // Write your code here

    int arr[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    for (int i = 0; i < 9 && amount; i++)
    {
        ans += amount / arr[i];
        amount = amount % arr[i];
    }

    return ans;
}
