//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<int> after(2*k+1,0);
        vector<int> curr(2*k+1,0);
        for(int ind =n-1;ind>=0;ind--){
            for(int transno=2*k-1;transno>=0;transno--){
                if(transno %2 ==0){
                   curr[transno]=max(-a[ind] + after[transno+1],after[transno]);
                }
                else  curr[transno]= max(a[ind]+after[transno+1],after[transno]);
            }
            after=curr;
        }
        return after[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends