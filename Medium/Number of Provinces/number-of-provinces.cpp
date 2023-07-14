//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

   class Solution {
    private:
    void dfs(int node,int vis[], vector<int>adjli[]){
        vis[node]=1;
        for(auto x: adjli[node]){
            if(!vis[x]){
            dfs(x,vis,adjli);
            }
        }
    }

    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjli[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjli[i].push_back(j);
                    adjli[j].push_back(i);
                }
            }
        }
        
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjli);
            }
            
        }
        
        return cnt;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends