//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
         int n = s.length();
        int i = 0;
        int j = 0;
        int minLen = 1e9;
        int count = 0;
        vector<int> map(3, 0);
        while(j < n){
            map[s[j]-'0']++;
            if(map[s[j]-'0'] == 1)count++;
            while(count == 3){
                minLen = min(minLen, j-i+1);
                map[s[i]-'0']--;
                if(map[s[i]-'0'] == 0)count--;
                i++;
            }
            j++;
        }
        return minLen == 1e9 ? -1: minLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends