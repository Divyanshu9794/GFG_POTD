//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//   public:
//     // Function to find the number of islands.
//     int numIslands(vector<vector<char>>& grid) {
//         // Code here
//     }
// };


class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == '1' && visit[i][j] == false){
                    ans++;
                    q.push({i, j});
                    
                    while(q.empty() == false){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0' ||  visit[x][y] == true)
                            continue;
                        visit[x][y] = true;
                        
                        int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
                        int dy[] = {-1, 0, +1, -1, +1, -1, 0, +1};
                        
                        for(int i=0; i<8; i++){
                            
                            q.push({x+dx[i], y+dy[i]});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends