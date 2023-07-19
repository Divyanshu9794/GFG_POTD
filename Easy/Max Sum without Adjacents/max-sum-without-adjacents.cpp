//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
		 int f(int ind,vector<int>&nums,vector<int>& dp){
       
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int p= nums[ind] + f(ind-2,nums,dp);
        int np = 0 + f(ind-1,nums,dp);

        return dp[ind]=max(p,np);
 }
    int findMaxSum(vector<int>&nums, int n) {
       vector<int> dp(n,-1);
       return f(n-1,nums,dp);
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends