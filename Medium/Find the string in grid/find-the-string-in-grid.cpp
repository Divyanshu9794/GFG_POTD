//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isvalid(int x, int y, int n, int m, vector<vector<char>>&grid, string &word)
{
    int di[]={1,0,-1,0,1,1,-1,-1};
    int dj[]={0,1,0,-1,1,-1,1,-1};
    
    for(int t=0;t<8;t++)
    {
        int i=x, j=y;
        int k=0;
        
        while(i>=0 && j>=0 && i<n && j<m && k<word.length() && grid[i][j]==word[k])
        {
            i+=di[t];
            j+=dj[t];
            k++;
        }
        
        if(k==word.length())
        return true;
    }
    return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>ans;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0] && isvalid(i,j,n,m,grid,word))
	            ans.push_back({i,j});
	        }
	    }
	    return ans;
	}
 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends