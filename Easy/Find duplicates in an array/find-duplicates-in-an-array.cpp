//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int nums[], int n) {
          vector<int> ans;

        for(int i=0;i<n;i++){

            nums[nums[i] % n] = nums[nums[i]%n] + n;

        }

        for(int i=0;i<n;i++){

            if(nums[i] >= 2*n){

                ans.push_back(i);

            }

        }

        if(ans.size() == 0)return{-1};

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends