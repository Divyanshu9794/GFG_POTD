//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

    Node* createMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        
        Node* targetNode = NULL;
        
        nodeToParent[root] = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* front = q.front();
            q.pop();
            
            if(front->left){
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            
            if(front->right){
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
            if(!targetNode and front->data == target) targetNode = front;
        }
        
        return targetNode;
    }
    
    void solve(Node* targetNode, int k, vector<int> &ans, map<Node*, Node*> &nodeToParent){
        
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int dist = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            bool changes = false;
            
            for(int i = 0; i<size; i++){
                
                Node* root = q.front();
                q.pop();
                
                if(root->left != NULL && !visited[root->left]){
                    visited[root->left] = true;
                    changes = true;
                    q.push(root->left);
                }
                
                if(root->right != NULL && !visited[root->right]){
                    visited[root->right] = true;
                    changes = true;
                    q.push(root->right);
                }
                
                if(nodeToParent[root] != NULL && !visited[nodeToParent[root]]){
                    visited[nodeToParent[root]] = true;
                    changes = true;
                    q.push(nodeToParent[root]);
                }
            }
            
            if(changes){
                
                dist++;
                
                if(dist == k){
                    size = q.size();
                    
                    for(int i = 0; i<size; i++){
                        
                        Node* front = q.front();
                        q.pop();
                        
                        ans.push_back(front->data);
                    }
                    
                    return;
                }
            }
        }
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        map<Node* , Node*> nodeToParent;
        Node* targetNode = createMapping(root, target, nodeToParent);
        vector<int> ans;
        solve(targetNode, k, ans, nodeToParent);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends