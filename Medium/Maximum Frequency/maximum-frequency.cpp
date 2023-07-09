//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxFrequency(int arr[], int n, int k) {
        // Code here
       sort(arr,arr+n);
        if(n == 1)return 1;
        int ans = INT_MIN;
        for(int i = n - 1 ;i >= 1;i--){
            int freq = 1;
            int diff = 0;
            for(int j = i -1;j>=0;j--){
                diff += arr[i]- arr[j];
                if(diff<=k)freq++;
                else break;
            }
            ans = max(ans,freq);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // testcases
    while (t--) {
        int n, k;
        cin >> n >> k; // total size of array and integer k

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling maxFrquency() function
        int ans = obj.maxFrequency(arr, n, k);

        cout << ans << endl;
    }
}
// } Driver Code Ends