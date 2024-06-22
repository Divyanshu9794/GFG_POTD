//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     long long ExtractNumber(string s) {
    int n = s.size();
    long long ans = -1; // Initialize answer to -1 (assuming no number without 9)

    for (int i = 0; i < n; i++) {
      if (!isdigit(s[i])) continue; // Skip non-digit characters

      else {
        bool isNine = false; // Flag to track if current number contains 9
        long long Number = 0; // Stores the current number being built

        while (i < n && isdigit(s[i])) { // Extract digits until end of string or non-digit
          int digit = s[i] - '0';
          if (digit == 9) isNine = true;
          Number = Number * 10 + digit;
          i++;
        }

        if (!isNine) ans = max(ans, Number); // Update answer if no 9 found
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends