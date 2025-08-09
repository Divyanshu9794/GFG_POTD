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
    // Function to check if two trees are identical.
    bool isIdentical(Node *a, Node *b) {
        // Your Code here
        if(a==NULL || b==NULL){
            return a==b;
        }
        return (a->data==b->data) && isIdentical(a->left,b->left) && isIdentical(a->right,b->right);
    }
};