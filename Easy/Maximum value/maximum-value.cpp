//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
      long long int findMaxValue(long long int arr[], int n) {
        // code here
        if (n < 4)
            return -1;
            
            
        long long int t1;
        long long int t2;
        long long int t3;
        long long int t4;

        t1 = -arr[0];
        t2 = arr[1] - arr[0];
        t3 = arr[1] - arr[0] - arr[2];
        t4 = arr[1] - arr[0] - arr[2] + arr[3];
        for (int i = 4;i < n;i++)
        {
            t1 = max(t1, -arr[i - 3]);
            t2 = max(t2, t1 + arr[i - 2]);
            t3 = max(t3, t2 - arr[i - 1]);
            t4 = max(t4, t3 + arr[i]);
        }
        return t4;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findMaxValue(arr, n) << endl;
    }
    return (0);
}

// } Driver Code Ends