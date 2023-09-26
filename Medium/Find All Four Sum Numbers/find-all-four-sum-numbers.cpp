//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int lo = j+1, hi = arr.size()-1;
                while(lo<hi){
                    int sum = arr[i]+arr[lo]+arr[j]+arr[hi];
                    
                    if(sum<k){
                        lo++;
                    }
                    else if(sum>k){
                        hi--;
                    }
                    else{
                        ans.push_back({arr[i],arr[j],arr[lo],arr[hi]});
                        lo++;hi--;
                    }
                }
            }
        }
        set<vector<int>>s;
        for(auto &vec:ans){
            s.insert(vec);
        }
        vector<vector<int>>ans1;
        for(auto vec:s){
            ans1.push_back(vec);
        }
        return ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends