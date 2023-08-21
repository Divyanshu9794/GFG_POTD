//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j;
        int ans=0;
        int dirx[]={1,-1,0,0,1,1,-1,-1};
        int diry[]={0,0,1,-1,1,-1,1,-1};
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(matrix[i][j])
                {
                    int cnt=0;
                    for(int k=0;k<8;k++)
                    {
                        int r = i+dirx[k];
                        int c = j+diry[k];
                        if(r>=0 && c>=0 && r<n && c<m && !matrix[r][c]) cnt++;
                    }
                    
                    if(cnt && cnt%2==0) ans++;
                }
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends