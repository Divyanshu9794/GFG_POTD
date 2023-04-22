//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  #include <bits/stdc++.h> 

int mod=(int)(1e9+7); 
int help(vector<int>&num,int tar,int in,vector<vector<int>>&dp)
{
   if(in<0)
   {
       if(tar==0) return 1;
       return 0;
   }
   if(dp[in][tar]!=-1)
   {
       return dp[in][tar];
   }
   int y=0;
   int x=help(num,tar,in-1,dp);
   if(tar-num[in]>=0)
    y=help(num,tar-num[in],in-1,dp);
   return dp[in][tar]=(x+y)%mod;
}
int findWays(vector<int> &num, int tar)
{
   int n=num.size();
   vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
   return help(num,tar,n-1,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalsum=0;
    for(auto &it:arr){
        totalsum +=it;
    }
    if(totalsum-d<0 || (totalsum-d)%2){
        return false;
    }
    return findWays(arr,(totalsum-d)/2);
}

    int findTargetSumWays(vector<int>&arr ,int target) {
        int n = arr.size();
        return countPartitions(n, target, arr);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
