//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int k,vector<int>&arr,int n,vector<int>&dp,int idx){
      
      if(idx==n-1)
      return 0;
      
      if(dp[idx]!=-1)
      return dp[idx];
      
      int ans=INT_MAX;
      for(int j=idx+1;j<=min(idx+k,n-1);j++)
      ans=min(ans,abs(arr[idx]-arr[j])+solve(k,arr,n,dp,j));
      return dp[idx]=ans;
  }
    int minimizeCost(int k, vector<int>& arr) {
        
        int n=arr.size();
        vector<int>dp(n,-1);
        
        return solve(k,arr,n,dp,0);
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends