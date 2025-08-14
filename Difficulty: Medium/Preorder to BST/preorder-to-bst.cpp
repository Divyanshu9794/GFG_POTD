class Solution {
  public:
    Node* build(vector<int>& pre, int &i, int bound) {
        if (i == pre.size() || pre[i] > bound) return NULL;

        Node* root = new Node; 
        root->data = pre[i++];
        root->left = root->right = NULL;

        root->left = build(pre, i, root->data);
        root->right = build(pre, i, bound);

        return root;
    }

    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        vector<int> preorder(pre, pre + size);
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
