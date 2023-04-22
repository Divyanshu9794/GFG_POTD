//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
         int mini = arr[0];
        for (int i = 0; i < n; i++) {
            mini = min(mini, arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] % mini != 0) {
                return 1;
            }
        }
        return mini;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}

