//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int newcolor,int deltarow[],int deltacol[],int inicolor ){
            ans[row][col]=newcolor;
            int n=image.size();
            int m=image[0].size();
            for(int i=0;i<4;i++){
                int nrow = row + deltarow[i];
                int ncol = col + deltacol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol] != newcolor){
                    dfs(nrow,ncol,ans,image,newcolor,deltarow,deltacol,inicolor);
                    
                }
            }
        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialcolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int deltarow[]={-1,0,+1,0};
        int deltacol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,newColor,deltarow,deltacol,initialcolor);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends