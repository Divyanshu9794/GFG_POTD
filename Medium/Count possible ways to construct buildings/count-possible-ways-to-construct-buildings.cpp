//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long calc(int i, int &N, vector<long long>&dp)
	{
	    if(i>=N)
	     return 1;
	    if(dp[i] != -1)
	     return dp[i];
	    return dp[i] = (calc(i+1,N, dp)%1000000007 +calc(i+2,N,dp)%1000000007)%1000000007;
	}
	int TotalWays(int N)
	{
	    // Code here
	    vector<long long>dp(N+1,-1);
	    long long a = (calc(0,N,dp)%1000000007);
	   // cout<<a<<endl;
	    return int((a*a)%1000000007);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends