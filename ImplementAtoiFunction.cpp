#include <bits/stdc++.h>
int atoi(string str)
{
    // Write your code here.
    int ans = 0;
    int n = str.length();
    int digit = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
        {
            ans += digit * (str[i] - '0');
            digit *= 10;
        }
    }
    if (str[0] == '-')
        ans = -ans;
    return ans;
}