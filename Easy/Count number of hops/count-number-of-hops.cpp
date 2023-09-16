//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    
    long long f(int n,vector<long long>&dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n==0){
            return dp[n]=1;
        }
       long long count=0;
        
        for(int i=1;i<=3;i++){
            if(n-i>=0){
            count=(count+f(n-i,dp))%mod;
            }
            
        }
        return dp[n]=count;
    }
    long long countWays(int n)
    {
        
        vector<long long>dp(n+1,-1);
        return f(n,dp);
        
    }

};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends