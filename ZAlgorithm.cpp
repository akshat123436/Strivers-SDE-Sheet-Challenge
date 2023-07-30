void createZarray(vector<int> &zArray, int len, string &s)
{
    int left = 0;
    int right = 0;
    for (int i = 1; i < len; i++)
    {
        if (i > right)
        {
            left = right = i;
            while (right < len && s[right] == s[right - left])
            {
                right++;
            }

            zArray[i] = right - left;
            right--;
        }
        else
        {
            int i1 = i - left;
            if (zArray[i1] < right - i + 1)
            {
                zArray[i] = zArray[i1];
            }
            else
            {
                left = i;

                while (right < len && s[right] == s[right - left])
                {
                    right++;
                }
                zArray[i] = right - left;
                right--;
            }
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
    string combinedString = p + "$" + s;

    int len = n + m + 1;

    vector<int> zArr(len);

    createZarray(zArr, len, combinedString);
    int ans = 0;
    for (int i = 1; i < len; i++)
    {
        if (zArr[i] == m)
            ans++;
    }

    return ans;
}