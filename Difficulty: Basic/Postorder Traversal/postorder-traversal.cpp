/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
public:
    void postordertraversal(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        postordertraversal(root->left,ans);
        postordertraversal(root->right,ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        postordertraversal(root,ans);
        return ans;
    }
};


    