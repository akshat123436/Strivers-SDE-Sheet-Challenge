#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // Write your code here.
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int first = s.top();
        s.pop();
        int second = s.top();
        s.pop();
        if (knows(first, second))
            s.push(second);
        else
            s.push(first);
    }

    int pos = s.top();
    for (int i = 0; i < n; i++)
    {
        if (i != pos)
        {
            if (!knows(i, pos) || knows(pos, i))
                return -1;
        }
    }

    return pos;
}