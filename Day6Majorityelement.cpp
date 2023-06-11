#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    map<int, int> mp;
    int ans = -1;
    int element = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (!count)
        {
            element = arr[i];
            count = 1;
            continue;
        }
        if (arr[i] == element)
            count++;
        else
            count--;
    }

    if (count)
    {
        int countElement = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element)
            {
                countElement++;
            }
        }
        if (countElement > n / 2)
            return element;
        else
            return -1;
    }
    else
        return -1;
}