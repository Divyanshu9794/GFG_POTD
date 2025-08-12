/*

Definition for Binary Tree Node
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
    void solve(Node*root,vector<int>temp,vector<vector<int>>&ans){
        if(root == NULL)return;
        
        temp.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
        }
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(root,temp,ans);
        return ans;
    }
};