#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *temp, *dummy = nullptr;
    if (!head)
        return head;
    while (head->next)
    {
        temp = head;
        head = head->next;
        temp->next = dummy;
        dummy = temp;
    }
    head->next = dummy;
    return head;
}