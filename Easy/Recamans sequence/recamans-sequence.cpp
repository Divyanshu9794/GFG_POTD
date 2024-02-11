//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> arr(n);
        unordered_map<int, int> mp;
        arr[0] = 0;
        arr[1] = 1;
        
        mp[0] = 1, mp[1] = 1;
        
        for(int i=2; i < n; i++){
            if(arr[i-1] - i > 0 && mp[arr[i-1] - i] == 0){
                arr[i] = arr[i-1] - i;
                mp[arr[i-1] - i]++;
            }
            else{
                arr[i] = arr[i-1] + i;
                mp[arr[i-1] + i]++;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends