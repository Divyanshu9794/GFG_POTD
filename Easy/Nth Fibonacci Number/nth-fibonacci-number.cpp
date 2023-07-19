//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        int p1=1;
        int p2=0;
        if(n==0){
            return p2;
        }
        for(int i=2;i<=n;i++){
            int c=(p1+p2)%1000000007;
            p2=p1;
            p1=c;
        }
        return p1;
        
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends