// User function template for C++

/*
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
    Node* divide(Node* head) {
        // code here
        queue<int>odd;
        queue<int>even;
        Node* temp=head;
        while(temp!=NULL){
        if((temp->data)%2){
            odd.push(temp->data);
        }
        else{
            even.push(temp->data);
        }
        temp=temp->next;
        }
        temp=head;
        while(!even.empty()){
            int ans=even.front();
            even.pop();
            temp->data=ans;
            temp=temp->next;
        }
        while(!odd.empty()){
            int ans=odd.front();
            odd.pop();
            temp->data=ans;
            temp=temp->next;
        }
        return head;
        
    }
};