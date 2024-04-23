//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int firstElement(int n) {
        int a00 = 1, a01 = 1, a10 = 1, a11 = 0;
        int b10 = 1, b11 = 0, mod = (int)1e9 + 7;
        
        if(n == 1)
            return a10;
        
        for(int i = 2; i <= n; i++) {
            int x = (b10 * a00 + b11 * a10) % mod;
            int y = (b10 * a01 + b11 * a11) % mod;
            b10 = x % mod;
            b11 = y % mod;
        }
        
        return b10 % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends