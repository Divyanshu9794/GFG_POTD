class Solution {
  public:
    // Function to delete a node from BST.
    
    Node* deleteNode(Node* root, int key) {
        if(root==NULL) return NULL;
        if(root->data==key) return helper(root);
        Node* dummy= root;
        while(root!=NULL){
            if(root->data>key){
                if(root->left!=NULL && root->left->data==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->data==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    Node* helper(Node* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        Node* rightchild = root->right;
        Node* lastright = findlastright(root->left);
        lastright->right = rightchild;
        return root->left;
    }
    Node* findlastright(Node* root){
        if(root->right==NULL) return root;
        return findlastright(root->right);
    }
};