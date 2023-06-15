#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *maker(LinkedListNode<int> *node, map<LinkedListNode<int> *, LinkedListNode<int> *> &corres)
{
    if (!node)
        return nullptr;
    if (!corres[node])
    {
        corres[node] = new LinkedListNode<int>(node->data);
        corres[node]->next = maker(node->next, corres);
        corres[node]->random = maker(node->random, corres);
    }
    return corres[node];
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *, LinkedListNode<int> *> corres;
    return maker(head, corres);
}
