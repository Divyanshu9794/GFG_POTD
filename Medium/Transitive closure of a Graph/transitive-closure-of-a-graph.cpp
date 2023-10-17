//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int u , vector<vector<int>> & graph, vector<int>& vis){
        vis[u] = 1;
        
        for(int v = 0 ; v < graph.size(); v++){
            if(graph[u][v] == 1 and !vis[v]){
                dfs(v , graph , vis);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < N ; i++){
            
            vector<int> vis(N , 0);
            
            dfs(i , graph , vis);
            
            ans.push_back(vis);
        }
        
        return ans;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends