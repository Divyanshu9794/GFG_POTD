/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* root) {
        // code here
        if(!root) return -1;
        int lh = 1+height(root->left);
        int rh = 1+height(root->right);
        return lh>rh?lh:rh;
    }
};