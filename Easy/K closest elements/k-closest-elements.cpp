//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  struct comp{
   
    bool operator() (pair<int,int>a, pair<int,int>b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    };
  
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(int i=0;i<n;i++){
            if(arr[i]-x != 0)
            pq.push({abs(arr[i]-x),i});
        }
        
        vector<int>ans;
        vector<int>hold;
        for(int i=0;i<k;i++){
            int index=pq.top().second;
            
            pq.pop();
            ans.push_back(arr[index]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends