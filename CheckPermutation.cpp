#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    int chars[26] = {};

    for (auto a : str1)
    {
        chars[a - 'a']++;
    }

    for (auto a : str2)
    {
        chars[a - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (chars[i] != 0)
            return false;
    }
    return true;
}