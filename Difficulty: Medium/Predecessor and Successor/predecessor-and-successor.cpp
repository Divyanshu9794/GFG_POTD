/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  Node* inorderPredecessor(Node* root, int &key) {
        Node* predecessor = NULL;

        while (root != NULL) {
            if (key <= root->data) {
                root = root->left;
            } else {
                predecessor = root;
                root = root->right;
            }
        }

        return predecessor;
    }
    
    Node* inordersuccessor(Node* root, int &key) {
        Node* successor = NULL;

        while (root != NULL) {
            if (key >= root->data) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        ans.push_back(inorderPredecessor(root,key));
        ans.push_back(inordersuccessor(root,key));
        return ans ;
        
        
    }

};
