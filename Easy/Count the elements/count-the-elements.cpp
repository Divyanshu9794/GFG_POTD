//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        vector<int>ans;
        vector<int>ptr=a;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        unordered_map<int,int>mp;
        int count=0;
        int j=0;
        int i=0;
        while(i<a.size() && j<b.size()){
            if(a[i]>=b[j]){
                count++;
               j++;
                
            }
            else{
                mp[a[i]]=count;
                
                i++;
            }
            
        }
        while(i<a.size()){
            mp[a[i]]=count;
            
            i++;
        }
        for(int i=0;i<q;i++){
            ans.push_back(mp[ptr[query[i]]]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends