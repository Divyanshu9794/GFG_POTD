//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    /*You are required to complete below function */
    void fill(Node*root,vector<int>&vec){
        if(!root){
            return;
        }
        fill(root->left,vec);
        vec.push_back(root->data);
        fill(root->right,vec); 
    }
    int inversionDuringMerging(int i,int mid,int j,vector<int>&inorder){
        //i-->mid and mid+1-->j
        int k1 = i, k2 = mid+1;
        vector<int>temp;
        int ct = 0;
        while(k1<=mid and k2<=j){
            if(inorder[k1] > inorder[k2]){
                temp.push_back(inorder[k2]);
                ct+=(mid-k1+1);
                k2++;
            }
            else{
                temp.push_back(inorder[k1]);
                k1++;
            }
        }
        while(k1<=mid){
            temp.push_back(inorder[k1]);
            k1++;
        }
        while(k2<=j){
            temp.push_back(inorder[k2]);
            k2++;
        }
        int ptr = 0;
        for(int k = i;k<=j;k++){
            inorder[k] = temp[ptr++];
        }
        return ct;
    }
    int solve(vector<int>&inorder,int i,int j){
        //returns number of inversion from i to j
        if(i>=j){
            return 0;
        }
        int mid = i+(j-i)/2;
        // i-->mid and mid+1-->j
        int t1 = solve(inorder,i,mid);
        int t2 = solve(inorder,mid+1,j);
        int t3 = inversionDuringMerging(i,mid,j,inorder);
        return t1+t2+t3;
    }
    int pairsViolatingBST(int n, Node *root) {
        if(!root){
            return 0;
        }
        vector<int>inorder;
        fill(root,inorder);
        return solve(inorder,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends