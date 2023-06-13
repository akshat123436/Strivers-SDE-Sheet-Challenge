/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *ptr1 = num1, *ptr2 = num2;

    int carry = 0;
    Node *prev = nullptr, *head;
    while (ptr1 && ptr2)
    {
        int res = ptr1->data + ptr2->data + carry;
        if (prev)
        {
            Node *temp = new Node(res % 10);
            prev->next = temp;
            prev = temp;
            carry = res / 10;
        }
        else
        {
            prev = new Node(res % 10);
            head = prev;
            carry = res / 10;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1)
    {
        int res = ptr1->data + carry;
        if (prev)
        {
            Node *temp = new Node(res % 10);
            prev->next = temp;
            prev = temp;
            carry = res / 10;
        }
        else
        {
            prev = new Node(res % 10);
            head = prev;
            carry = res / 10;
        }
        ptr1 = ptr1->next;
    }
    while (ptr2)
    {
        int res = ptr2->data + carry;
        if (prev)
        {
            Node *temp = new Node(res % 10);
            prev->next = temp;
            prev = temp;
            carry = res / 10;
        }
        else
        {

            prev = new Node(res % 10);
            head = prev;
            carry = res / 10;
        }
        ptr2 = ptr2->next;
    }

    while (carry)
    {
        int res = carry;
        if (prev)
        {
            Node *temp = new Node(res % 10);
            prev->next = temp;
            prev = temp;
            carry = res / 10;
        }
        else
        {
            prev = new Node(res % 10);
            head = prev;
            carry = res / 10;
        }
    }

    return head;
}
