//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
public:
    ll reversedBits(ll x) {
        ll res = 0, i = 0;
        
        while(i < 32) {
            res <<= 1;
            
            if(x & 1)
                res |= 1;
            
            x >>= 1, i++;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends