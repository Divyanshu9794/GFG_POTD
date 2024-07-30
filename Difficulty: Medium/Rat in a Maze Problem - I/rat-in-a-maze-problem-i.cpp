//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    map<pair<int, int>, char> mp;

    void dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& vis, vector<string>& res, string path) {
        int n = mat.size();
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }
        vis[i][j] = 1;
        for (auto dir : dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;

            if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || mat[x][y] == 0)
                continue;

            dfs(mat, x, y, vis, res, path + mp[{dir[0], dir[1]}]);
        }
        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        mp[{0, 1}] = 'R';
        mp[{1, 0}] = 'D';
        mp[{-1, 0}] = 'U';
        mp[{0, -1}] = 'L';

        int n = mat.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (mat[0][0] == 1) {
            dfs(mat, 0, 0, vis, res, "");
        }
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends