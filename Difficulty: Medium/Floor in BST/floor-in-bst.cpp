// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
        int f =-1;
        while(root){
            if(root->data==input){
                f = root->data;
                return f;
            }
            if(input>root->data) {
                f = root->data;
                root= root->right;
            }
            else{
                root= root->left;
            }
        }
        return f;
    }
};