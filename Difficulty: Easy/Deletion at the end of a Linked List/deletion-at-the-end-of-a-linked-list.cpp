/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        // code here
        Node* temp = head;
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        while(temp->next->next != NULL){
            temp = temp -> next;
        }
        delete temp ->next;
        temp->next = NULL;
        return head;
    }
};