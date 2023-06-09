#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int ptr = arr1.size() - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0 && ptr >= 0)
    {
        if (arr1[m] > arr2[n])
        {
            arr1[ptr] = arr1[m];
            m--;
        }
        else
        {
            arr1[ptr] = arr2[n];
            n--;
        }
        ptr--;
    }
    while (m >= 0 && ptr >= 0)
    {
        arr1[ptr] = arr1[m];
        ptr--;
        m--;
    }
    while (n >= 0 && ptr >= 0)
    {
        arr1[ptr] = arr2[n];
        ptr--;
        n--;
    }

    return arr1;
}