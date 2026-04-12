// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *deleteHead(Node *head) {
    // Your code here
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* pre = head;
    head = head->next;
    head -> prev = NULL;
    pre -> next = NULL;
    delete pre;
    return head;
    
}
