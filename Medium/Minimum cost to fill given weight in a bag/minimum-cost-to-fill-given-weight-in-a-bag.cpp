//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     int solve(int index,int n, int w, vector<int>&cost,vector<vector<int>>&dp){
        if(w==0)return 0;
        if(index==n||w<0)return INT_MAX;
        if(dp[index][w]!=-1)return dp[index][w];
        int exclude=solve(index+1,n,w,cost,dp);
        int include=INT_MAX;
        if(w>=(index+1) && cost[index]!=-1){
            int next_cost=solve(index,n,w-(index+1),cost,dp);
            if(next_cost!=INT_MAX){
                include=cost[index]+next_cost;
            }
        }
        return dp[index][w]=min(include,exclude);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        int result= solve(0,n,w,cost,dp);
        return result==INT_MAX?-1:result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends