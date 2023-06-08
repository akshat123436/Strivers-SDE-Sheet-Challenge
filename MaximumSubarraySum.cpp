#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    long long int sum = 0;
    long long int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > 0)
        {
            sum += arr[i];
            maxsum = max(maxsum, sum);
        }
        else
            sum = 0;
    }

    return maxsum;
}