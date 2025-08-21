// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};*/

class Solution {
public:
    int countnode(Node* root){
        if(root == NULL) return 0;
        int ans = 1+ countnode(root->left) + countnode(root->right);
        return ans;
    }
    bool iscbt(Node* root, int i, int cnt){
        if(root==NULL) return true;
        if(i>=cnt) return false;
        else{
            bool left = iscbt(root->left,2*i+1,cnt);
            bool right = iscbt(root->right,2*i+2,cnt);
            return left&&right;
        }
    }
    bool ismaxorder(Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = ismaxorder(root->left);
            bool right = ismaxorder(root->right);
            return (left&&right) && (root->data > root->left->data && root->data > root->right->data);
        }
    }
    bool isHeap(Node* root) {
        int i =0;
        int count = countnode(root);
        if(iscbt(root,i,count) && ismaxorder(root)){
            return true;
        }
        return false;
    }
};
