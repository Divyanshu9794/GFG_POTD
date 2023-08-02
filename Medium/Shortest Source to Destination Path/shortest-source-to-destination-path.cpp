//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[] = {0,-1,0,+1};
        int dc[] = {-1,0,+1,0};
        vis[0][0]=1;
        while(!pq.empty()){
            int step= pq.top().first;
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();
            if(r==x && c==y){
                return step;
            }
            else{
                for(int i=0;i<4;i++){
                    int newrow=r+dr[i];
                    int newcol=c+dc[i];
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && a[newrow][newcol]==1){
                        vis[newrow][newcol]=1;
                        pq.push({step+1,{newrow,newcol}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends