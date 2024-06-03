//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    long long int dp[100005][3];
    long long int f(int i, int prev, int n)
    {
        
        if(i>=n) return 1;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        long long int cnt=0;
        if( prev==-1 )
        {
            cnt+=f(i+1,0,n)+f(i+1,1,n);
            cnt=cnt%mod;
        }
        else if(prev==0 )
        {
            cnt+=f(i+1,0,n)+f(i+1,1,n);
            cnt=cnt%mod;
        }
        else
        {
        cnt+=f(i+1,0,n);
        cnt=cnt%mod;
        } 
        return dp[i][prev+1]= cnt%mod;
    }
    long long int poww(int n)
    {
       long long  int x=1;
        for(int i=1;i<=n;i++)
        {
            x=x*1LL*2;
            x=x%mod;
        }
        return x;
    }
    int numberOfConsecutiveOnes(int n)
    {
    
        memset(dp,-1,sizeof(dp));
       return (poww(n)-f(0,-1,n)+mod)%mod; 
       
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends