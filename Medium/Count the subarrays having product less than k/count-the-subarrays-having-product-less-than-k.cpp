//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        int result = arr[0];
        int c=0;
 
        for (int i = 0; i < n; i++) {
            long long mul = arr[i];
            if(mul<k){
                c++;
            }
            for (int j = i + 1; j < n; j++) {
                
                mul *= arr[j];
                if(mul<k){
                    c++;
                }
                if(mul>=k){
                    break;
                }
            }
           
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends