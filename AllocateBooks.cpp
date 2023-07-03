#include <bits/stdc++.h>
bool checker(long long val, vector<int> &time, int n, int m)
{
    long long temp = 0;
    int count = 1;

    for (int i = 0; i < m; i++)
    {
        if (temp + time[i] > val)
        {
            count++;
            temp = time[i];
        }
        else
            temp += time[i];
    }
    // cout << val << " " << count << endl;
    return count <= n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long low = INT_MIN, high = 0;

    for (auto a : time)
    {
        if (a > low)
            low = a;

        high += a;
    }

    while (high - low > 0)
    {
        long long mid = (high + low) / 2;

        if (checker(mid, time, n, m))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return high;
}