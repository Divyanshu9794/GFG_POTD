/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    
    int height(Node* root, int &d){
        if(!root){
            return 0;
        }
        int lh = height(root->left,d);
        int rh = height(root->right,d);
        d= max(d,rh+lh);
        return 1+ max(lh,rh);
    }
    int diameter(Node* root) {
        int d=0;
        height(root,d);
        return d;
    }
};