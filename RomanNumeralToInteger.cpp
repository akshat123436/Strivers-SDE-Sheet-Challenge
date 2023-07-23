int val(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
}
int romanToInt(string s)
{
    // Write your code here
    int ans = 0;
    int n = s.length();
    ans += val(s[n - 1]);
    for (int i = 0; i < n - 1; i++)
    {
        int cur = val(s[i]);
        int next = val(s[i + 1]);
        if (cur >= next)
        {
            ans += cur;
        }
        else
        {
            ans -= cur;
        }
    }

    return ans;
}