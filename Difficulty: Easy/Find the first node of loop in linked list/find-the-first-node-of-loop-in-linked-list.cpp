// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node* fast = head;
        Node* slow = head;
        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                slow= head;
                while(slow!=fast){
                    slow= slow->next;
                    fast = fast->next;  
                }
                return slow ; //recolliding again
            }

        }
        return NULL;
    }
};