#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> copyp = permutation;
    vector<int> lastOnes;
    int k = -1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (copyp[i] < copyp[i - 1])
        {
            lastOnes.push_back(copyp[i]);
        }
        else
        {
            lastOnes.push_back(copyp[i]);
            int index = lower_bound(lastOnes.begin(), lastOnes.end(), copyp[i - 1]) - lastOnes.begin();
            int temp = lastOnes[index];
            lastOnes[index] = copyp[i - 1];
            copyp[i - 1] = temp;
            k = i - 1;
            break;
        }
    }
    if (k == -1)
    {
        sort(copyp.begin(), copyp.end());
    }
    else
    {
        int ptr = 0;
        for (int i = k + 1; i < n; i++)
        {
            copyp[i] = lastOnes[ptr];
            ptr++;
        }
    }

    return copyp;
}