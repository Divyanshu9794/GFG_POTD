//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>>adj(n , vector<int>(n , INT_MAX));
        adj[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        pq.push({adj[0][0] , {0 , 0}});
        vector<pair<int,int>> directions = {{1 , 0} , {-1 , 0} , {0 , -1} , {0 , 1}};
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int dist = top.first;
            int row = top.second.first;
            int col = top.second.second;
            for(auto i : directions)
            {
                int nrow = row + i.first;
                int ncol = col + i.second;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && dist + grid[nrow][ncol] < adj[nrow][ncol])
                {
                    adj[nrow][ncol] = dist + grid[nrow][ncol];
                    pq.push({adj[nrow][ncol] , {nrow , ncol}});
                }
            }
        }
        using Cell = pair<int,int>;
        
        return adj[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends