#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    // Write your code here.
    stack<int> s;
    int size;

public:
    int min;

    // Constructor
    minStack()
    {
        // Write your code here.
        min = INT_MAX;
        size = 0;
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        if (num < min)
            min = num;
        size++;
        s.push(num);
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (!size)
            return -1;
        size--;
        int val = s.top();
        s.pop();
        int newMin = INT_MAX;
        if (val == min)
        {
            stack<int> q;
            while (!s.empty())
            {
                q.push(s.top());
                int v = s.top();
                newMin = newMin < v ? newMin : v;
                s.pop();
            }
            while (!q.empty())
            {
                s.push(q.top());
                q.pop();
            }
            min = newMin;
        }
        return val;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (!size)
            return -1;
        return s.top();
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (!size)
            return -1;
        return min;
    }
};