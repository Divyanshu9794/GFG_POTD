//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     int calc(int i,int total,vector<int> &c, vector<vector<int>>&dp)
    {
        if(i==c.size())
         return 0;
        if(dp[i][total] !=-1)
         return dp[i][total];
        if(total>=c[i])
        {
            int t = total-c[i] +(c[i]*9)/10;
            return dp[i][total] = max(1+calc(i+1,t,c,dp),calc(i+1,total,c,dp));
        }
        return dp[i][total] = calc(i+1,total,c,dp);
    }
    int max_courses(int n, int total, vector<int> &c)
    {
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return calc(0,total,c,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends