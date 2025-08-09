class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        queue<Node*> q;
        q.push(root);
        bool ltor = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                int index = (ltor) ? i : (n - 1 - i);
                level[index] = node->data;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            ltor = !ltor; 
            for (int val : level) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};
