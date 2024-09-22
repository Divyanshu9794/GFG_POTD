//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
     int lps(string str) {
        int n = str.length();
        vector<int> lps(n, 0); // LPS array initialization
        int length = 0; // Length of the previous longest prefix suffix
        
        // Loop to calculate the LPS array
        for (int i = 1; i < n; i++) {
            while (length > 0 && str[i] != str[length]) {
                length = lps[length - 1]; // Backtrack if mismatch
            }
            if (str[i] == str[length]) {
                length++;
            }
            lps[i] = length;
        }
        
        return lps[n - 1]; // The last value in LPS array is the answer
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends