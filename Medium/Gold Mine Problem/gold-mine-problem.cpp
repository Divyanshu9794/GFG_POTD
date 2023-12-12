//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans = INT_MIN;
        for(int i = m-2; i >= 0; i-- )
        {
            for(int j = n-1; j >= 0; j--)
            {
                int a = 0;
                int b = 0;
                int c = 0;
                if(j+1<n)
                {
                    a = M[j+1][i+1];
                }
                if(j-1>=0)
                {
                    b = M[j-1][i+1];
                }
                c = M[j][i+1];
                M[j][i] = M[j][i] + max(a, max(b,c));
                if(M[j][i]>ans)
                {
                    ans = M[j][i];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends