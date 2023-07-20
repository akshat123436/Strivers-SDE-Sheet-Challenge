class Queue
{
    // Define the data members(if any) here.
    stack<int> pusher, popper;
    int size;
    int frontElement;

public:
    Queue()
    {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        if (!size)
            frontElement = val;
        size++;

        while (!popper.empty())
        {
            pusher.push(popper.top());
            popper.pop();
        }
        pusher.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (!size)
            return -1;
        size--;
        while (!pusher.empty())
        {
            popper.push(pusher.top());
            pusher.pop();
        }

        int val = popper.top();
        popper.pop();
        if (size)
            frontElement = popper.top();
        return val;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (!size)
            return -1;
        return frontElement;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return !size;
    }
};