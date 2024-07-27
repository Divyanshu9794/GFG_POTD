//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int lcs(string & s, string & t) {
  int n=s.length(),m=t.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){

            if(i==0 or j==0){

                dp[i][j]=0;

            }

            else if(s[i-1]==t[j-1]){

                dp[i][j]=1+dp[i-1][j-1];

            }

            else{

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }

        }

    }

    return dp[n][m];
}
    int longestPalinSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int countMin(string str){
        return str.length()-longestPalinSubseq(str);
    
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends