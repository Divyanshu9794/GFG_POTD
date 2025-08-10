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
    Node* lca(Node* root, int a, int b) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == a || root->data == b) {
            return root;
        }
        Node* leftLCA = lca(root->left, a, b);
        Node* rightLCA = lca(root->right, a, b);
        if (leftLCA != NULL && rightLCA != NULL) {
            return root;
        }
        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }
};
