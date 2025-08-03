/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
       Node* first=head;
       if(head==NULL){
           return -1;
           
       }
       for(int i=0;i<k;i++){
           if(first==NULL){
               return -1;
           }
           first=first->next;
       }
       Node* second=head;
       while(first!=NULL){
           second=second->next;
           first=first->next;
       }
       return second->data;
    }
};