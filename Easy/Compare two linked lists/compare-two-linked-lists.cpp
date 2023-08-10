//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};  


int compare(Node *list1, Node *list2); 


int main()
{
 int t,n;
 cin>>t;
 char x;
 while(t--)
 {
 cin>>n;
 cin>>x;
  Node *list1 = new Node(x);
    Node *temp=list1;
    for(int i=0;i<n-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
		int m;
		cin>>m;
    cin>>x;
    Node *list2 = new Node(x);
    temp=list2;
    for(int i=0;i<m-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
 
    cout << compare(list1, list2)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
     // Code Here
     Node*temp1=list1;
     Node*temp2=list2;
     int c1=0,c2=0;
     while(temp1 and temp2)
     {
         int data1=temp1->c;
         int data2=temp2->c;
         if(data1>data2) return 1;
         else if(data1<data2) return -1;
         
        temp1=temp1->next;
        temp2=temp2->next;
     }
     
     
     if(!temp1 and !temp2) return 0;
     else if(temp1) return 1;
     else return -1;
     
}