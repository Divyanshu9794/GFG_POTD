//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        long long ans=1,a=2,mod=1000000007;
        for(int i=2;i<=n;i++)
        {
            long long temp=1;
            for(int j=i;j>0;j--)
                temp=(temp*(a++))%mod;
            ans=(ans+temp)%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends