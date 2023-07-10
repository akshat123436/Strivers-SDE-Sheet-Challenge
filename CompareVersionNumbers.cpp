#include <bits/stdc++.h>
void removeZero(string &s)
{
    int n = s.length();
    int m = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (s[i] == '0' && s[i - 1] == '.')
        {
            m = i - 1;
            i--;
        }
        else
        {
            break;
        }
    }
    s = s.substr(0, m);
}
int compareVersions(string a, string b)
{
    removeZero(a);
    removeZero(b);
    // cout << a << " " << b << endl;
    int ones = 0, twos = 0, onee = 0, twoe = 0;
    while (1)
    {
        while (b[twoe] != '.' && twoe < b.length())
        {
            twoe++;
        }
        while (a[onee] != '.' && onee < a.length())
        {
            onee++;
        }

        if (onee == twoe)
        {
            while (ones < onee)
            {
                if (a[ones] < b[twos])
                    return -1;
                else if (a[ones] > b[twos])
                    return 1;
                ones++;
                twos++;
            }
        }
        else
        {
            if (onee > twoe)
                return 1;
            else
                return -1;
        }

        if (ones == a.length() && twos == b.length())
            return 0;
        if (ones == a.length())
            return -1;
        if (twos == b.length())
            return 1;
        onee++;
        twoe++;
    }
}