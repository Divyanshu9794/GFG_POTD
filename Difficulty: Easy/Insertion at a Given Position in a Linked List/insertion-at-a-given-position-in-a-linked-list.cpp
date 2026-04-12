/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        // code here
        if(head==NULL){
            if(pos == 1){
                return new Node(val);
            }
            else{
                return head;
            }
        }
        if(pos==1){
            Node *newnod =  new Node(val);
            newnod->next= head;
            return newnod;
            
        }
        int c = 0;
        Node* temp = head;
        while(temp!=NULL){
            c++;
            if(c==pos-1){
                Node *x = new Node(val);
                x->next = temp->next;
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};