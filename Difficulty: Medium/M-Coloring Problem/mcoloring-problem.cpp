class Solution {
  public:
    bool check(vector<vector<int>> &adj,int curcolor,vector<int> &color,int src){
         
         for(int it:adj[src]){
            if(color[it] == curcolor)return false;
         }
         return true;
    }
    bool solve(vector<vector<int>> &adj,int v,int m,vector<int> &color,int src){
         //base condition
        if(src == v){
            return true;
        }
        
        for(int i=1;i<=m;i++){
            if(check(adj,i,color,src)){
                color[src]=i;
                if(solve(adj,v,m,color,src+1))return true;
                color[src]=0;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> color(v,0);
        
        return solve(adj,v,m,color,0);
        
    }
};