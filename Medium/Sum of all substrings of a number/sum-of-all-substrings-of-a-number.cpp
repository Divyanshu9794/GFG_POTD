//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int C = 1e9+7;
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long solve(string&s,int i,vector<long long int>&dp){
        if(i==0){
            return (s[i]-'0')%C;
        }
        if(dp[i]!=-1){
            return dp[i]%C;
        }
        long long t = solve(s,i-1,dp);
        t = (t*10)%C;
        t = (t+(i+1)*(s[i]-'0'))%C;
        return dp[i] = t%C;
    }
    long long sumSubstrings(string s){
        vector<long long int>dp(s.size(),-1);
        long long int ans = 0;
        for(int i=0;i<s.size();i++){
            ans = (ans+solve(s,i,dp))%C;
        }
        return ans%C;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends