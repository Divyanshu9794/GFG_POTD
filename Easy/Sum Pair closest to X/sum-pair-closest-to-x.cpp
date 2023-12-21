//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        vector<int>v;
        int i=0,j=arr.size()-1, first = arr[i],second = arr[j];
        while(i<j){
            int sum = arr[i]+arr[j];
            if(abs(sum-x)<abs((second+first)-x)){
                first = arr[i];
                second = arr[j];
            }
            if(sum<x) i++;
            else j--;
        }
        v.push_back(first);
        v.push_back(second);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends