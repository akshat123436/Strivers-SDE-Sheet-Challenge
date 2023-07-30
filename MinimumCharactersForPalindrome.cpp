#include <bits/stdc++.h>
int minCharsforPalindrome(string str)
{
    string changed = str + "$";
    reverse(str.begin(), str.end());
    changed += str;

    vector<int> arr(changed.size());

    int j = 0;
    int i = 1;

    while (i < changed.size())
    {
        if (changed[i] == changed[j])
        {
            arr[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j)
            {
                j = arr[j - 1];
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }

    int n = 1;

    n = max(n, arr[changed.size() - 1]);

    return (str.length() - n);
}