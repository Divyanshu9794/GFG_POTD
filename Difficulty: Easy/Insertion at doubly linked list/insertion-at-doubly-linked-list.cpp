/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {

        Node* newNode = new Node(x);

        // If list is empty
        if (head == nullptr)
            return newNode;

        Node* temp = head;
        int index = 0;

        // Move to p-th node (NOT p-1)
        while (temp != nullptr && index < p) {
            temp = temp->next;
            index++;
        }

        // If position is invalid
        if (temp == nullptr)
            return head;

        // Insert AFTER position p
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;

        return head;
    }
};