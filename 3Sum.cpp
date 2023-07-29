#include <bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum > K)
            {
                k--;
            }
            else if (sum < K)
            {
                j++;
            }
            else
            {
                triplets.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    // sort(triplets.begin(), triplets.end());
    return triplets;
}