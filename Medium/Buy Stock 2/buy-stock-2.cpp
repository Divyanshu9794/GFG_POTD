//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector <long long>> dp(n+1,vector<long long> (2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0 ;buy<=1;buy++){
                long long p;
                if(buy){
                     p = max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
                }
                else{
                    p = max((prices[ind] + dp[ind+1][1]),dp[ind+1][0]);
                }
                dp[ind][buy] = p;
            }
        }
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends