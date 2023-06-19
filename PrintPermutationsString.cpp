#include <bits/stdc++.h>
void recursor(vector<string> &ans, int i, string &s, string &temp, vector<bool> &isPicked)
{
    if (i == s.length())
    {

        ans.push_back(temp);

        return;
    }
    for (int j = 0; j < s.length(); j++)
    {
        if (!isPicked[j])
        {
            temp.push_back(s[j]);
            isPicked[j] = true;
            recursor(ans, i + 1, s, temp, isPicked);
            temp.pop_back();
            isPicked[j] = false;
        }
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    int n = s.length();
    vector<string> ans;
    vector<bool> isPicked(n);
    string temp;
    recursor(ans, 0, s, temp, isPicked);
    return ans;
}