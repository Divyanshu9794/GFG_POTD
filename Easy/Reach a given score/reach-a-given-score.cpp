//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	int coins[] = {3,5,10};
        vector<long> dp(n+1,0);
        dp[0] = 1;
        for(int x:coins){
            for(int j=x;j<=n;j++){
                dp[j] += dp[j-x];
        
            }
        }
        return dp[n];
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends