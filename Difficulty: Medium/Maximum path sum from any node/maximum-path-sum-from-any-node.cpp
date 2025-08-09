// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


class Solution {
  public:
  int maxsum(Node* root, int &maxi){
        if(!root) return 0;
        int left = max(0,maxsum(root->left,maxi));
        int right = max(0,maxsum(root->right,maxi));
        maxi = max(maxi , left+right+root->data);
        return max(left,right)+ root->data;

    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        maxsum(root,maxi);
        return maxi; 
        
    }
};