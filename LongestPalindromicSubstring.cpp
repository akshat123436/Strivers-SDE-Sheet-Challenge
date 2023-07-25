string longestPalinSubstring(string str)
{
    // Write your code here.
    int maxLen = 0;
    int n = str.length();
    string ans;
    for (int i = 0; i < n; i++)
    {
        string pal;
        int left = i, right = i;

        while (str[left] == str[right] && left >= 0 && right < n)
        {
            left--;
            right++;
        }
        left++;
        right--;

        if (right - left + 1 > maxLen)
        {
            maxLen = right - left + 1;
            ans = str.substr(left, right - left + 1);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            string pal;
            int left = i, right = i + 1;

            while (str[left] == str[right] && left >= 0 && right < n)
            {
                left--;
                right++;
            }
            left++;
            right--;

            if (right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                ans = str.substr(left, right - left + 1);
            }
        }
    }
    return ans;
}