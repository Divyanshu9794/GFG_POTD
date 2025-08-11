// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        Node* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    Node* build(vector<int>& preorder,int prestart, int preend,vector<int>& inorder,int instart,int inend,map<int,int> &inmp){
        if(prestart>preend || instart>inend){
            return NULL;
        }
        Node* root = new Node(preorder[prestart]);
        int inroot = inmp[root->data];
        int numsleft = inroot - instart;
        root->left = build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inmp);
        root->right = build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inmp);
        return root;
    }
};