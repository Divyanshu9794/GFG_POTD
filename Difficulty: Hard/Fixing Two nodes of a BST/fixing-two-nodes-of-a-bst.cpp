/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    protected:
    void inorder(vector<int> &ans, Node* root){
        if(!root)
        return;
        inorder(ans, root->left);
        ans.push_back(root->data);
        inorder(ans, root->right);
    }
    void replace_bst(vector<int> &ans, Node* root, int &index){
    
        if(!root)
        return;
        replace_bst(ans, root->left, index);
        root->data= ans[index++];
        replace_bst(ans, root->right, index);
        
    }
  public:
    void correctBST(Node* root) {
        // add code here.
        
    vector<int> ans;
    
    inorder(ans, root);
    int index=0;
    // sort(ans.begin(), ans.end());
    int pivot1=-1;
    int pivot2=-1;
    for (int i=0; i<ans.size()-1; i++){
        if(ans[i]> ans[i+1]){
            if(pivot1==-1){
                pivot1= i;
                pivot2= i+1;
            }
            else{
                pivot2= i+1;
            }
        }
        
    }
    if(pivot2==-1){
        pivot2= ans.size()-1;
    }
    swap(ans[pivot1], ans[pivot2]);
    replace_bst(ans, root, index);
    
    
    }
};