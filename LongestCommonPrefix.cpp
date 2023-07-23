string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string prefix;
    int minLength = 1e9;

    for (auto &a : arr)
    {
        if (a.length() < minLength)
        {
            prefix = a;
            minLength = a.length();
        }
    }

    for (auto &a : arr)
    {
        string temp;
        for (int i = 0; i < minLength; i++)
        {
            if (a[i] == prefix[i])
                temp.push_back(a[i]);
            else
                break;
        }
        prefix = temp;
        minLength = prefix.length();
    }

    return prefix;
}
