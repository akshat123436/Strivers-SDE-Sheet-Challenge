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

Node *findMiddle(Node *head)
{
    // Write your code here
    Node *slow = head, *ans = head, *last = head, *fast = head;

    while (fast)
    {
        ans = slow;
        slow = slow->next;
        last = fast;
        if (fast->next)
            fast = fast->next->next;
        else
            fast = fast->next;
    }

    if (last->next)
    {
        // even
        return slow;
    }
    else
        return ans;
}
