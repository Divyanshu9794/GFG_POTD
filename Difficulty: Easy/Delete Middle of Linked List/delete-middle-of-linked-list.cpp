/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
        // Your Code Here
        
        if(head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        Node* slow =head;
        Node* fast=head;
        fast = fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        Node* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
    }
};