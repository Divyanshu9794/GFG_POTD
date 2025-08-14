bool search(Node* root, int val) {
    while (root != NULL) {
        if (root->data == val) {
            return true;
        }
        else if (val < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return false;
}
