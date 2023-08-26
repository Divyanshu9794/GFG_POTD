//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int k) 
    {
        // your code here
        int dp[k+1][e+1];
        for(int i=1;i<=e;i++){
            dp[1][i]=1;
            dp[0][i]=0;
            
        }
        for(int j=1;j<=k;j++){
            dp[j][1]=j;
        }
        for(int i=2;i<=k;i++){
            for(int j=2;j<=e;j++){
                dp[i][j]=INT_MAX;
                for(int x=1;x<=i;x++){
                    dp[i][j]=min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
                }
            }
        }
        return dp[k][e];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends