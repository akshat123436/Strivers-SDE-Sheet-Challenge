#include <bits/stdc++.h>

void insert(stack<int> &s, int temp)
{
    if (!s.size() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int num = s.top();
    s.pop();
    insert(s, temp);
    s.push(num);
}

void sortStack(stack<int> &stack)
{
    if (!stack.size())
        return;
    // Write your code here
    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, temp);
}