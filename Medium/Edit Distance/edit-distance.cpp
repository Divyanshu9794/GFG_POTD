//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int i,int j , string &s,string &t,vector<vector<int>> &dp){
      if(i<0){
          return j+1;
      }
      if(j<0){
          return i+1;
          
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      if(s[i]==t[j]){
          return dp[i][j] = f(i-1,j-1,s,t,dp);
      }
      return dp[i][j]= 1+ min(f(i-1,j,s,t,dp),min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp)));
  }
    int editDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends