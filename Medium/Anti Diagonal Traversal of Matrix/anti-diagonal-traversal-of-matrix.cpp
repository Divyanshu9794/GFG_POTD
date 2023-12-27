//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
          vector<int>ans;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int k=0,j=i;
            while(k<n && j>=0){
                ans.push_back(matrix[k][j]);
                k++;j--;
            }
        }
        for(int i=1;i<n;i++){
            int j=n-1;
            int k=i;
            while(k<n && j>=0){
                ans.push_back(matrix[k][j]);
                k++;j--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends