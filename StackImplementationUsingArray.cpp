// Stack class.
class Stack
{
    int arr[1000];
    int head;
    int limit;

public:
    Stack(int capacity)
    {
        // Write your code here.
        head = 0;
        limit = capacity;
    }

    void push(int num)
    {
        // Write your code here.
        if (head < limit)
        {
            arr[head++] = num;
        }
    }

    int pop()
    {
        // Write your code here.
        if (!head)
            return -1;
        int val = arr[--head];
        return val;
    }

    int top()
    {
        // Write your code here.
        if (!head)
            return -1;
        return arr[head - 1];
    }

    int isEmpty()
    {
        // Write your code here.
        return !head;
    }

    int isFull()
    {
        // Write your code here.
        return head == limit;
    }
};
