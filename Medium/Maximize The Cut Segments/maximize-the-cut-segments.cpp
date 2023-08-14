//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int a, int b, int c)
    {
        //Your code here
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=-1;
            if(i-a>=0){
                dp[i]=max(dp[i],dp[i-a]);
            }
            if(i-b>=0){
                dp[i]=max(dp[i],dp[i-b]);
            }
            if(i-c>=0){
                dp[i]=max(dp[i],dp[i-c]);
            }
            if(dp[i]!=-1){
                dp[i]++;
            }
            
        }
        int ans = dp[n];
        if(ans<0){
            return 0;
        }
        else{
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends