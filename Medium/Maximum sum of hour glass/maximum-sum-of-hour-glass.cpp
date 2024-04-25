//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int ans=-1;
        int sum=0;
        int fr=0;
        int sr=0;
        int lr=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                fr=mat[i-1][j-1]+mat[i-1][j]+mat[i-1][j+1];
                sr=mat[i][j];
                lr=mat[i+1][j-1]+mat[i+1][j]+mat[i+1][j+1];
                sum=fr+sr+lr;
                ans=max(ans,sum);
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
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends