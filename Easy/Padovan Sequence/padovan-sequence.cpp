//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       const int MOD = 1000000007;
    if (n == 0 || n == 1 || n == 2) return 1;
    vector<int> seq(n + 1);
    
    seq[0] = 1;
    seq[1] = 1;
    seq[2] = 1;

    // Computing the sequence iteratively
    for (int i = 3; i <= n; i++) {
        seq[i] = (seq[i - 2] + seq[i - 3]) % MOD;
    }

    // Returning the nth value of the sequence
    return seq[n];
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends