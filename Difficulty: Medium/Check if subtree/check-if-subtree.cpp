/* A binary tree node

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
    bool isSameTree(Node* a, Node* b) {
        if (!a && !b) return true; 
        if (!a || !b) return false; 
        if (a->data != b->data) return false;
        return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }

    bool isSubTree(Node* root, Node* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true; 
        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }
};
