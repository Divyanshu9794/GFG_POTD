//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        int prev=1;
        int prev_prev=1;
        int curr;
        int mod=pow(10,9)+7;
        for(int i=2;i<=n;i++)
        {
          curr=(prev+prev_prev)%mod;
          prev_prev=prev;    
          prev=curr;    
        }
        return curr;
    }


};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends