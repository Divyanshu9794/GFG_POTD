/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/



class Solution {
public:

    void inorder(Node* root,vector<int> &in){
    if(root==NULL){
        return ;

    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}

    bool findTarget(Node* root, int target) {
        vector<int> in;
        inorder(root,in);
        int i=0;
        int j = in.size()-1;
        while(i<j){
            if(in[i]+in[j]==target){
                return 1;
            }
            else if(in[i]+in[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return 0;
        
    }
};