//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   void kthLargest(int arr[], int n, int k)
//     {
//     }
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        
        priority_queue <int, vector<int>, greater<int>>pq(arr,arr+k);
        for(int i=0; i<k-1; i++)
        {
            
            ans.push_back(-1);
        }
        ans.push_back(pq.top());
        for(int i=k; i<n;i++)
        {
            
            if(arr[i]>pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        ans.push_back(pq.top());
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends