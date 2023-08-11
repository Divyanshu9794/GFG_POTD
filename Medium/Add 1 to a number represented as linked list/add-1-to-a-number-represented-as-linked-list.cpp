//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(!head) return head;
        stack<int>s, t;
        
        Node* p= head;
        while(p){
            s.push(p->data);
            p=p->next;
        }
        
        int carry=0,i=0;
        Node* res= new Node(-1), *tmp=res;
        while(!s.empty()){
            int x= s.top(); s.pop();
            int sum= i==0? x+1+carry: x+carry;
            carry= sum/10;
            t.push(sum%10);
            i++;
        }
        if(carry) t.push(carry);
        while(!t.empty()){
            int x=t.top(); t.pop();
            tmp->next= new Node(x);
            tmp=tmp->next;
        }
        return res->next;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends