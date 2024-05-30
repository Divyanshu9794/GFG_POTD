//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string s, string t) {
        int MOD = int(1e9) + 7;
        int N = s.size(), M = t.size();
        vector<int> prev(M + 1), cur(M + 1);
        
        for (int i = 1; i <= N; i++) {
            prev[0] = 1;
            for (int j = 1; j <= M; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = ((prev[j - 1] % MOD) + (prev[j] % MOD)) % MOD;
                } else {
                    cur[j] = prev[j] % MOD;
                }
            }
            prev = cur;
        }
        
        return prev[M];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends