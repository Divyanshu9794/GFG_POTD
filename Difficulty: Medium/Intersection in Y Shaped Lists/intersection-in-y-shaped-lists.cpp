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
    Node* intersectPoint(Node* headA, Node* headB) {
        //  Code Here
        Node* t1= headA;
        Node* t2 = headB;
        if(t1==NULL || t2==NULL){
            return NULL;
        }
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==NULL) t1 = headB;
            if(t2==NULL) t2= headA;

        }
        return t1;
    }
};