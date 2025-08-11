/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  Node* build(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend , map<int,int> &mp){
        if(poststart>postend || instart>inend){
            return NULL;
        }
        Node* root= new Node(postorder[postend]);
        int inroot = mp[postorder[postend]];
        int numsleft = inroot - instart;
        root->left = build(inorder,instart,inroot-1,postorder,poststart,poststart+numsleft-1,mp);
        root->right = build(inorder,inroot+1,inend,postorder,poststart+numsleft, postend-1,mp);
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        // code here
        
    }
};