/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        // Code Here
        if(head==NULL){
            return new Node(x);
        }
        Node* fast = head;
        Node* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newnode = new Node(x);
        newnode -> next = slow->next;
        slow->next = newnode;
        return head;
    }
};