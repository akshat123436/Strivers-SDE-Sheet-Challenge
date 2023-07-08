#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    // Write your code here.
    string ans = "1";

    for (int i = 1; i < n; i++)
    {
        string newString;
        for (int j = 0; j < ans.length();)
        {
            char c = ans[j];
            int count = 0;
            while (c == ans[j] && j < ans.length())
            {
                count++;
                j++;
            }
            newString.push_back(count + '0');
            newString.push_back(c);
        }
        ans = newString;
    }

    return ans;
}