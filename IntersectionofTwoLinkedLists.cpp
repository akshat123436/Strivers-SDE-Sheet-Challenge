/****************************************************************

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

*****************************************************************/
#include <stack>
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *ans = nullptr;

    stack<Node *> firstq, secondq;

    while (firstHead != nullptr)
    {
        firstq.push(firstHead);
        firstHead = firstHead->next;
    }
    while (secondHead != nullptr)
    {
        secondq.push(secondHead);
        secondHead = secondHead->next;
    }

    while (firstq.top() == secondq.top())
    {
        ans = firstq.top();
        firstq.pop();
        secondq.pop();
    }

    return ans;
}