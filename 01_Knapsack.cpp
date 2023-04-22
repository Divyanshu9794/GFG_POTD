//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
int f(int ind,int W,int weight[],int val[],vector<vector<int>> &dp){
	if(ind==0){
		if(weight[0]<=W){
			return val[0];

		}
		return 0;

	}
	if(dp[ind][W]!=-1){
		return dp[ind][W];
	}
	int nottake = 0+f(ind-1,W,weight,val,dp);
	int take=INT_MIN;
	if(weight[ind]<=W){
		take = val[ind] +f(ind-1,W-weight[ind],weight,val,dp);

	} 
	return dp[ind][W]=max(take,nottake);
}
    int knapSack(int W, int weight[], int value[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
	return f(n-1,W,weight,value,dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends