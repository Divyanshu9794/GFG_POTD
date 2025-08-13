/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   
    Node* LCA(Node* root, Node* a, Node* b) {
        if(root==NULL) return NULL;
        int current = root->data;
        if(current < a->data && current < b->data){
            return LCA(root->right,a,b);
        }
        if(current>a->data && current>b->data){
            return LCA(root->left,a,b);
        }
        return root;
    }
};