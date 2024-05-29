//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<int> dp(n+1,0);
       
       for(int i=0;i<=n;i++)
       {
           if(dp[i]==0)
           {
               if(i+1<=n)
                dp[i+1] = 1;
               if(i+x<=n)
                dp[i+x] = 1;
               if(i+y<=n)
                dp[i+y] = 1;
           }
       }
       return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends