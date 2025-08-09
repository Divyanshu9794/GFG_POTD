/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void addLeft(Node* root,vector<int> &ans){
        Node* curr=root->left;
        while(curr!=NULL){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left!=NULL){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
    }
    void addRight(Node* root,vector<int> &ans){
        Node* curr=root->right;
        vector<int> temp;
        while(curr!=NULL){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right!=NULL){
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        }
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
        
    }
    void leafnode(Node* root,vector<int> &ans){
        if(root==NULL) return;
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        leafnode(root->left,ans);
        leafnode(root->right,ans);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        addLeft(root,ans);
        leafnode(root,ans);
        addRight(root,ans);
        return ans;
    }
};