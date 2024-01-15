//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int prev,int m,int n)
    {
        if(prev>m)
            return 0;
        if(n==0)
            return 1;
        int ans=0;
        for(int i=prev*2;i<=m;i++)
        {
            if(i>0)
                ans += helper(i,m,n-1);
        }
        return ans;
    }
    int numberSequence(int m, int n){
        // code here
        return helper(0,m,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends