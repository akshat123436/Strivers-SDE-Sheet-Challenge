#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    int ans = 1;

    unordered_map<char, int> count;

    count[input[0]]++;
    int n = input.length();
    int ptr1 = 0, ptr2 = 1;
    while (ptr2 < n)
    {
        if (count[input[ptr2]])
        {
            count[input[ptr1]]--;
            ptr1++;
        }
        else
        {
            count[input[ptr2]]++;
            ptr2++;
        }
        ans = max(ans, ptr2 - ptr1);
    }

    return ans;
}