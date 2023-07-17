//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
private:
    
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){
    vis[node]=1;
    pathvis[node]=1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis)){
                return true;
            }
            
        }
       else  if(pathvis[it]){
            return true;
        }
        
        
    }
    pathvis[node]=0;
    return false;
}
 public:
 
   
	bool isPossible(int n,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[n];
    
    for(int i=0;i<prerequisites.size();i++){
        
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        
    }
    
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
           if(dfs(i,adj,vis,pathvis)){
               return false;
           }
        }
    }
    
    return true;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends