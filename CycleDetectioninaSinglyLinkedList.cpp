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

bool detectCycle(Node *head)
{
    //	Write your code here
    Node *slow = head, *fast = head->next;

    while (slow != fast && slow && fast)
    {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            fast = fast->next;
    }

    if (slow == fast)
        return true;
    else
        return false;
}