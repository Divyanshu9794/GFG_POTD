//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void f(int ind,vector<int> &A,vector<vector<int>> &ans,vector<int> &ds,int t){
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<A.size();i++){
            if(i>ind && A[i]==A[i-1]) continue;
            if(A[i]>t) break;
            ds.push_back(A[i]);
            f(i+1,A,ans,ds,t-A[i]);
            ds.pop_back();
        }
        
    }
  
    vector<vector<int>> combinationSum2(vector<int> &A, int t) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(A.begin(),A.end());
        f(0,A,ans,ds,t);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends