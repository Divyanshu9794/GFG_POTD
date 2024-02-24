//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            if(n == 0 || n==1) return n;
            int val1 = n/2, val2 = n/3, val3 = n/4;
            int ans1 = maxSum(val1) + maxSum(val2) + maxSum(val3);
            return max(ans1,n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends