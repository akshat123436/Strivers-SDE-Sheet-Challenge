#include <stack>
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *prev = nullptr;

    int i = 1;

    int n = 0;

    Node *temp = head;
    stack<Node *> s;
    while (temp)
    {
        s.push(temp);
        temp = temp->next;
    }

    while (K)
    {
        temp = s.top();
        s.pop();
        K--;
    }
    if (s.size())
    {
        s.top()->next = temp->next;
        delete temp;
    }
    else
    {
        head = temp->next;
        delete temp;
    }
    return head;
}
