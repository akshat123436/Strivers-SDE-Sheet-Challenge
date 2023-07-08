#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int sum = 0;
    int expected = n * (n + 1) / 2;
    long long ssum = 0;
    long long sExpected = (n * 1LL * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ssum += arr[i] * arr[i];
    }
    int misMinusAdd = expected - sum;
    int misPlusAdd = (sExpected - ssum) / misMinusAdd;

    int missing = (misMinusAdd + misPlusAdd) / 2;
    int added = (misPlusAdd - misMinusAdd) / 2;

    return {missing, added};
}
