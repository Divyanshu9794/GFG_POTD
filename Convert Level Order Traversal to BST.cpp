//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    if(n==0){
        return NULL;
    }
    Node *root= new Node(arr[0]);
    queue<pair<Node*,pair<int,int>>> qu;
    qu.push({root,{INT_MIN,INT_MAX}});
    int i;
    for(i=1;i<=n-1;i++){
        Node*temp = qu.front().first;
        pair<int,int>p = qu.front().second;
           if(arr[i] > p.first &&  arr[i] < p.second)
           {
              if(arr[i] < temp->data)
              {
                 temp->left = new  Node(arr[i]);
                 qu.push({temp->left,{p.first,temp->data}});
              }
              else
              {
                 qu.pop(); 
                 temp->right = new Node(arr[i]);
                 qu.push({temp->right,{temp->data,p.second}});
              }
           }
           else
           {
              i--; 
              qu.pop();
           }
}
return root;
 
}
