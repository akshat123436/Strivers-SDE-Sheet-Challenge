#include <bits/stdc++.h>
bool checker(int num, int c, vector<int> &pos, int n)
{
    int count = 1;
    int prev = pos[0];
    for (int i = 1; i < n; i++)
    {
        if (pos[i] - prev >= num)
        {
            count++;
            prev = pos[i];
        }
    }
    return count >= c;
}
int chessTournament(vector<int> positions, int n, int c)
{
    // Write your code here
    sort(positions.begin(), positions.end());
    int low = 0, high = positions[positions.size() - 1] - positions[0];
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (checker(mid, c, positions, n))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (checker(high, c, positions, n))
        return high;
    return low;
}