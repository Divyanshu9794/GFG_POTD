/* Link list Node
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
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int k) {
        // code here
        Node* temp = head;
        Node* prev = NULL;
        if(head==NULL){
            return head;
        }
        if(k==1){
            temp=head;
            head = head->next;
            delete temp;
            return head;
        }
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                prev ->next = prev->next->next;
                delete temp;
                break;
                
            }
            prev = temp;
            temp=temp->next;
        }
        return head;
    }
};