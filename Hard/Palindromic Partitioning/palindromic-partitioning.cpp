//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int pal(string &s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    
    int dp[501][501];
    
    int answer(string &str, int i, int j, vector<vector<int>>&pre)
    {
        if(i >= j)
            return 0;
        
        
        if(pre[i][j] == 1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = 1000;
        
        for(int k = i; k < j; k++)
        {
            int left = 1000, right = 1000;
            if(dp[i][k] != -1)
                left = dp[i][k];
            else
            {
                left = answer(str,i,k,pre);
                dp[i][k] = left;
            }
            if(dp[k+1][j] != -1)
                right = dp[k+1][j];
            else
            {
                right = answer(str,k+1,j,pre);
                dp[k+1][j] = right;
            }
            mini = min(mini, 1 + left + right);
        }
        return dp[i][j] = mini;
    }

    int palindromicPartition(string &str)
    {
        // code here
        int n = (int)str.length();
        vector<vector<int>>pre(n,vector<int>(n,0));
        
        for(int i= 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                pre[i][j] = pal(str,i,j);
            }
        }
        memset(dp, -1, sizeof dp);
        return answer(str, 0, n-1, pre);
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