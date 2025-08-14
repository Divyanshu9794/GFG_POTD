/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


class Solution {
public:
    int count = 0;
    int ans;
    void inorder(Node *root, int K){
        if(root == NULL){
            return ;
        }
        inorder(root->left,K);
        if(count == K-1){
            ans = root->data;
        }
        count++;
        inorder(root->right,K);
    }
    int kthSmallest(Node* root, int K) {
        inorder(root,K);   
        if(count < K){
            return -1;
        }
        return ans;
    }
};