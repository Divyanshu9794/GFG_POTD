/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int findlen(Node* slow,Node* fast){
        int c = 1;
        slow = fast->next;
        while(slow!=fast){
            slow = slow->next;
            c++;
        }
        return c;
    }
    int lengthOfLoop(Node *head) {
        // code here
        Node * slow = head;
        Node * fast = head;
        int c =0;
        while(fast!= NULL && fast->next!=NULL){
            slow = slow ->next;
            fast = fast->next->next;
            if(slow == fast){
                return findlen(slow,fast);
            }
            
        }
        return 0;
    }
};