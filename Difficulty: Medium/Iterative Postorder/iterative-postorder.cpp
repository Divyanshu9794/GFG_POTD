// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector<int> post;
        if (!root) return post;
        
        Node* cur = root;
        while (cur) {
            if (!cur->right) {
                post.push_back(cur->data);
                cur = cur->left;
            } else {
                Node* prev = cur->right;
                while (prev->left && prev->left != cur) {
                    prev = prev->left;
                }
                if (!prev->left) {
                    prev->left = cur;
                    post.push_back(cur->data);
                    cur = cur->right;
                } else {
                    prev->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(post.begin(), post.end());
        return post;
    }
};
