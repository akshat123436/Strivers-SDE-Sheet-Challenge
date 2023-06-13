Node<int> *ptr = nullptr;
if (first && second)
{
    if (first->data < second->data)
    {
        ptr = new Node<int>(first->data);
        first = first->next;
    }
    else
    {
        ptr = new Node<int>(second->data);
        second = second->next;
    }
}
else
{
    if (first)
    {
        ptr = new Node<int>(first->data);
        first = first->next;
    }
    else if (second)
    {
        ptr = new Node<int>(second->data);
        second = second->next;
    }
    else
        return ptr;
}
Node<int> *head = ptr;
while (first || second)
{

    if (first && second)
    {
        Node<int> *temp = new Node<int>(first->data < second->data ? first->data : second->data);
        if (first->data < second->data)
            first = first->next;
        else
            second = second->next;
        ptr->next = temp;
        ptr = temp;
    }
    else if (second)
    {
        Node<int> *temp = new Node<int>(second->data);
        second = second->next;
        ptr->next = temp;
        ptr = temp;
    }
    else
    {
        Node<int> *temp = new Node<int>(first->data);
        first = first->next;
        ptr->next = temp;
        ptr = temp;
    }
}
return head;