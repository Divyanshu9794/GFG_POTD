/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


class Solution {
public:
    void preordertraversal(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        preordertraversal(root->left,ans);
        preordertraversal(root->right,ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preordertraversal(root,ans);
        return ans;
    }
};


    