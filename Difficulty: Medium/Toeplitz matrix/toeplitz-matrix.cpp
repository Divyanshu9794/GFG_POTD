//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        if(i<m && mat[i][i]!=mat[0][0]){
            return 0;
        }
    }
    return 1;
}