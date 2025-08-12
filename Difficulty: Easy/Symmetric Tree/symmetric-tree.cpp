class Solution {
  public:
    bool check(Node* root1, Node* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (!(root1 && root2)) return false;
        
        if (root1->data != root2->data) return false;
        
        bool leftCheck = check(root1->left, root2->right);
        bool rightCheck = check(root1->right, root2->left);
        
        return leftCheck && rightCheck;
    }
    
    bool isSymmetric(Node* root) {
        if (!root) return true; // empty tree is symmetric
        return check(root->left, root->right);
    }
};
