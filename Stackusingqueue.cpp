class Stack
{
    // Define the data members.
    queue<int> master, helper;
    int topElement;
    int size;

public:
    Stack()
    {
        // Implement the Constructor.
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return !size;
    }

    void push(int element)
    {
        // Implement the push() function.
        topElement = element;
        master.push(element);
        size++;
    }

    int pop()
    {
        // Implement the pop() function.
        if (!size)
            return -1;
        size--;
        while (master.size() != 1)
        {
            helper.push(master.front());
            master.pop();
        }
        int val = master.front();
        master.pop();
        int newtopElement = 0;
        while (!helper.empty())
        {
            master.push(helper.front());
            newtopElement = helper.front();
            helper.pop();
        }
        topElement = newtopElement;
        return val;
    }

    int top()
    {
        if (!size)
            return -1;
        return topElement;
    }
};