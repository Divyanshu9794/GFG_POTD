//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int ind,int w,int val[], int wt[],vector<vector<int>> &dp){
    if(ind==0){
        return ((int)(w/wt[0]))*val[0];

    }
    if(dp[ind][w]!=-1){
        return dp[ind][w];
    }
    int nottake= 0+f(ind-1,w,val,wt,dp);
    int take=0;
    if (wt[ind] <= w) {
      take = val[ind] + f(ind, w - wt[ind], val, wt,dp);
    }
    return dp[ind][w]= max(take,nottake);
}
    int knapSack(int n, int w, int val[], int wt[])
    {
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
        return f(n-1,w,val,wt,dp);
    }




};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends