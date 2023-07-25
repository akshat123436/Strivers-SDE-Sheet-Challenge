/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *createFlatten(Node *node)
{
    if (!node || !(node->next))
        return node;

    Node *secondNode = createFlatten(node->next);
    node->next = nullptr;
    Node *temp = new Node();
    Node *result = temp;
    Node *firstNode = node;

    while (firstNode && secondNode)
    {
        if (firstNode->data < secondNode->data)
        {
            temp->child = firstNode;
            firstNode = firstNode->child;
        }
        else
        {
            temp->child = secondNode;
            secondNode = secondNode->child;
        }
        temp = temp->child;
    }

    // while(firstNode){
    // 	temp->child = firstNode;
    // 	firstNode = firstNode->child;
    // 	temp = temp->child;

    // }
    // while(secondNode){
    // 	temp->child = secondNode;
    // 	secondNode = secondNode->child;
    // 	temp = temp->child;

    // }

    if (firstNode)
        temp->child = firstNode;
    else
        temp->child = secondNode;

    return result->child;
}
Node *flattenLinkedList(Node *head)
{
    return createFlatten(head);
}
