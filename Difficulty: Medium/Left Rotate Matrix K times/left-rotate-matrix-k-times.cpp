//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rotateleftbyk(vector<vector<int>> &mat,int k,int i)
    {
        int n=mat[i].size();
        k=k%n;
        reverse(mat[i].begin(),mat[i].begin()+k);
        reverse(mat[i].begin()+k,mat[i].end());
        reverse(mat[i].begin(),mat[i].end());
    }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            rotateleftbyk(mat,k,i);
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends