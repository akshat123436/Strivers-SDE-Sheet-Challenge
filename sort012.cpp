#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c0++;
        }
        else if (arr[i] == 2)
        {
            c2++;
        }
        else
            c1++;
    }
    int i = 0;
    while (c0)
    {
        arr[i] = 0;
        c0--;
        i++;
    }
    while (c1)
    {
        arr[i] = 1;
        c1--;
        i++;
    }
    while (c2)
    {
        arr[i] = 2;
        c2--;
        i++;
    }
    //   Write your code here
}