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
    Node* sortedMerge(Node* list1, Node* list2) {
        // code here
        Node* t1 = list1;
        Node* t2 = list2;
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while(t1 != NULL && t2!= NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2=t2->next;
            }
        }
        if(t1) temp->next = t1;
        else temp ->next =t2;

        return dummy ->next;
        
    }
};