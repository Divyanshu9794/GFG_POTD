//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
        int maxl=0, maxr=n-1;
        vector<int> left(n, 0), right(n, 0);
        vector<bool> ans;
        left[0]=0, right[n-1]=n-1;
        for(int i=1;i<n;i++){
            if(a[i-1]<a[i]){
                maxl=i;
            }
            if(a[n-i]<a[n-i-1]){
                maxr=n-i-1;
            }
            right[n-i-1]=maxr;
            left[i]=maxl;
        }
        for(auto it: queries){
            int first=it.first, second=it.second;
            if(right[first]>=left[second]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
// } Driver Code Ends