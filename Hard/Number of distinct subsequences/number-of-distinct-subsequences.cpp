//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  
	int mod=1e9+7;
	int distinctSubsequences(string s)
	{
	    int n=s.size();
	    int dp[n+1]={0};
	    vector<int> last(256,-1);
	    dp[0]=1;
	    for(int i=1;i<=n;i++){
	        dp[i]=(2*dp[i-1])%mod;
	        if(last[s[i-1]]!=-1)dp[i]-=dp[last[s[i-1]]];
	        dp[i]%=mod;
	        last[s[i-1]]=i-1;
	    }
	    if(dp[n]<0)dp[n]+=mod;
	    return dp[n]%mod;
	}
 
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends