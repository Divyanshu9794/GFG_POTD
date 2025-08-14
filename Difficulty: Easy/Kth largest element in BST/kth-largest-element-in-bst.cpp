/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void inorder(Node* root,vector<int> &a){
        if(root!=NULL){
            inorder(root->left,a);
            a.push_back(root->data);
            inorder(root->right,a);
            
        }
        
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> a;
        inorder(root,a);
        return a[a.size()-K];
    }
};