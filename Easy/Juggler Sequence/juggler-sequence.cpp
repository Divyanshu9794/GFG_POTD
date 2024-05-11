//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<long long>ans;
   map<long long,long long>mp;
   int recur(long long x){
       if(x <= 1) return 0;
       if(mp[x] != 0) return mp[x];
       mp[x] = 1;
       if(x % 2 == 0){
           x = sqrt(x);
           ans.push_back(x);
           return recur(x);
       }
       if(x % 2 == 1){
           x = x * sqrt(x);
           ans.push_back(x);
           return recur(x);
       }
   }
  
    vector<long long> jugglerSequence(long long n) {
        // code here
        ans.push_back(n);
        int dummy = recur(n);
        
        return ans;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends