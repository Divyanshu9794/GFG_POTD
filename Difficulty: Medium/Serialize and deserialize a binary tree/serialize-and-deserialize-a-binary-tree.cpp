class Solution {
  public:
    vector<int> serialize(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur == NULL) {
                ans.push_back(-1);
            } else {
                ans.push_back(cur->data);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    Node* deSerialize(vector<int> &arr) {
        if (arr.empty()) return NULL;
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* node = q.front();
            q.pop();
            if (arr[i] != -1) {
                node->left = new Node(arr[i]);
                q.push(node->left);
            } else {
                node->left = NULL;
            }
            i++;
            if (i >= arr.size()) break;
            if (arr[i] != -1) {
                node->right = new Node(arr[i]);
                q.push(node->right);
            } else {
                node->right = NULL;
            }
            i++;
        }
        return root;
    }
};
