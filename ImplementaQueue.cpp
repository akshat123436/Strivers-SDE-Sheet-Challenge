#include <bits/stdc++.h>
struct Node
{
    Node *next;
    int data;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Queue
{
public:
    Node *f = nullptr;
    Node *end = nullptr;
    int size = 0;
    Queue()
    {
        // Implement the Constructor
        f = nullptr;
        end = nullptr;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return !size;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (size)
        {
            Node *temp = new Node(data);
            end->next = temp;
            end = temp;
        }
        else
        {
            Node *temp = new Node(data);
            end = f = temp;
        }
        size++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (size)
        {
            size--;
            Node *temp = f;
            f = f->next;
            int val = temp->data;
            delete temp;
            return val;
        }
        return -1;
    }

    int front()
    {
        // Implement the f() function
        if (!size)
            return -1;
        return f->data;
    }
};