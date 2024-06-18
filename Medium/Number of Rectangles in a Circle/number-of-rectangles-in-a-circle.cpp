//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      int rectanglesInCircle(int r) {
        // code here
         int count = 0;
        int limit = 2 * r;

        for (int w = 1; w <= limit; ++w) {
            for (int h = 1; h <= limit; ++h) {
                if (w * w + h * h <= 4 * r * r) {
                    count++;
                }
            }
        }

        return count;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends