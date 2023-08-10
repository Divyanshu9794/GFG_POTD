//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node* reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
struct Node * mergeResult(struct Node *node1,struct Node *node2){
    node1=reverse(node1);
    node2=reverse(node2);
    if(!node1)
    return node2;
    if(!node2)
    return node1;
    struct Node* temp=new Node();
    temp->data=-1;
    Node* ans=temp;
    while(node1&&node2){
        if(node1->data>node2->data){
            temp->next=node1;
            temp=node1;
            node1=node1->next;
        }
        else{
            temp->next=node2;
            temp=node2;
            node2=node2->next;
        }
    }
    while(node1){
        temp->next=node1;
            temp=node1;
            node1=node1->next;
    }
    while(node2){
        temp->next=node2;
            temp=node2;
            node2=node2->next;
    }

    ans=ans->next;
    return ans;
}