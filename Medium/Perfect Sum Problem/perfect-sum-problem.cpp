//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    int mod = (1e9 + 7);
    public:
        int f(int ind , int sum,int arr[],vector<vector<int>>&dp){
       
        if(ind == 0){
            if(sum == 0 && arr[0] == 0){
                return 2;
            }
            else if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }

       int pick = 0;
        if(sum >= arr[ind]){
            pick = f(ind - 1, sum-arr[ind],arr,dp);
        }
        else pick = false;
        int notPick = f(ind - 1 , sum,arr,dp);
        return dp[ind][sum] = (pick%mod + notPick%mod)%mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
     
        for(int i = 0; i<sum+1; i++){
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        
        
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j < sum + 1; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j]%mod + dp[i-1][j - arr[i-1]]%mod;
                }
                else dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][sum]%mod;
    }
      
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends