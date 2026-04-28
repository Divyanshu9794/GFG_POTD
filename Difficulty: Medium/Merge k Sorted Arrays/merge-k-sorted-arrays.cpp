class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> ans;
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                ans.push_back(mat[i][j]);  
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};