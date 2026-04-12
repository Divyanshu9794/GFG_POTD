/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node *head)
{
    Node *prev = NULL, *next = NULL;
    Node *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
struct Node *addTwoLists(struct Node *num1, struct Node *num2)
{
    if (!num1)
        return num2;
    if (!num2)
        return num1;
    num1 = reverse(num1);
    num2 = reverse(num2);
    int sum = 0;
    int carry = 0;
    Node *temp = NULL;
    Node *head = NULL;
    Node *tail = NULL;
    while (num1 || num2 || carry)
    {
        sum = carry + (num1 ? num1->data : 0) + (num2 ? num2->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        temp = new Node(sum);
        if (!head)
        {
            head = temp;
        }
        else
        {
            tail->next = temp;
        }
        tail = temp;
        if (num1)
            num1 = num1->next;
        if (num2)
            num2 = num2->next;
    }
    head = reverse(head);
    while (head->data == 0 && head->next)
    {
        head = head->next;
    }
    return head;
}
};

