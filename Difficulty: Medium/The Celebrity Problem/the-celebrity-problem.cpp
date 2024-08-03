//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        if( n == 1) return 0 ;
        int m = mat[0].size();
        vector<vector<int>> adj(n);
        vector<int> cnt(n,0);
        for(int i = 0; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(mat[i][j]) {
                    adj[i].push_back(j);
                    cnt[j] ++;
                }
            }
        }
        for(int i = 0 ; i < n ;i ++) {
            if( cnt[i] == n - 1 && adj[i].size() == 0) {
                return i ;
            }
        }
        return - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends