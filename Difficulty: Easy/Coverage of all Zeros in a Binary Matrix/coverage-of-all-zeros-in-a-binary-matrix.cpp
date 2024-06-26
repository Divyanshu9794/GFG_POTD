//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int coverage =0;
        int m=matrix.size();
        int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                    if((j-1)>=0 && matrix[i][j-1]==1){
                        coverage++;
                    }
                     if( (j+1)<n && matrix[i][j+1]==1){
                        coverage++;
                    }
                     if((i-1)>=0 && matrix[i-1][j]==1){
                        coverage++;
                    }
                     if((i+1)<m && matrix[i+1][j]==1){
                        coverage++;
            }
            }
        }
    }
    return coverage;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends