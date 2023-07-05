//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

    int NumberofLIS(int n, vector<int>&arr) {
     
        int maxi=1;
        vector<int> dp(n,1),count(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(arr[j]<arr[i] && dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);
            
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                c+=count[i];
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends