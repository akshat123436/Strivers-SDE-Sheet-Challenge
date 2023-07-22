#include <vector>

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> fakeLis;

    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(fakeLis.begin(), fakeLis.end(), arr[i]) - fakeLis.begin();

        if (index == fakeLis.size())
        {
            fakeLis.push_back(arr[i]);
        }
        else
        {
            fakeLis[index] = arr[i];
        }
    }

    return fakeLis.size();
}
