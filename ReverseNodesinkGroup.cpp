#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    Node *temp = head;

    vector<int> a;

    while (temp)

    {

        a.push_back(temp->data);

        temp = temp->next;
    }

    int sum = 0;

    for (int i = 0; i < n; i++)

    {

        reverse(a.begin() + sum, min(a.begin() + sum + b[i], a.end()));

        sum += b[i];
    }

    temp = head;

    int i = 0;

    while (temp)

    {

        temp->data = a[i++];

        temp = temp->next;
    }

    return head;
}