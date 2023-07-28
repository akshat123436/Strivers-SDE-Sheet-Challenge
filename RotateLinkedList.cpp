/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    // Write your code here.
    int n = 0;
    Node *temp = head, *last = head;

    while (temp)
    {
        last = temp;
        n++;
        temp = temp->next;
    }

    k = k % n;

    if (!k)
        return head;
    Node *ptr1 = head, *ptr2 = head;
    for (int i = 0; i < k; i++)
    {
        ptr1 = ptr1->next;
    }
    Node *prev = head;
    while (ptr1)
    {
        ptr1 = ptr1->next;
        prev = ptr2;
        ptr2 = ptr2->next;
    }

    prev->next = nullptr;
    last->next = head;
    return ptr2;
}