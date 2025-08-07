/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/


class Solution {
public:
    void inOrdertraversal(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        inOrdertraversal(root->left,ans);
        ans.push_back(root->data);
        inOrdertraversal(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inOrdertraversal(root,ans);
        return ans;
    }
};


    