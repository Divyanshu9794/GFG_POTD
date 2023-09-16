//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        // code here
        
        int n = str.length();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int gap =1;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j=i+gap;
                if(isPalindrome(i,j,str)){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                    }
                    
                }
                
            }
        }
        return dp[0][n-1];
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends