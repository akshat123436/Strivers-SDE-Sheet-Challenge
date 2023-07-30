#include <bits/stdc++.h>

void makeLength(vector<int> &arr, string &s)
{
    int i = 1;
    int j = 0;

    for (; i < s.length();)
    {
        while (i < s.length() && s[i] != s[j])
            i++;
        while (i < s.length() && s[i] == s[j])
        {
            arr[i] = j + 1;
            i++;
            j++;
        }
        if (j)
            j = arr[j - 1];
    }
}

bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> patternPrefix(p.length());

    int i = 1;
    int j = 0;

    while (i < p.length())
    {
        if (p[i] == p[j])
        {
            patternPrefix[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j)
            {
                j = patternPrefix[j - 1];
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }
    int first = 0, second = 0;

    while (first < p.length() && second < s.length())
    {
        if (p[first] == s[second])
        {
            first++;
            second++;
        }
        else
        {
            if (first)
                first = patternPrefix[first - 1];
            else
            {
                first = 0;
                second++;
            }
        }
    }
    if (first == p.length())
        return true;
    return false;
}