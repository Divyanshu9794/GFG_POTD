//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int> ans(arr.begin(),arr.end());
        sort(ans.begin(),ans.end());
        unordered_map<long long,long long> map;
        long long sum=0;
        for(int i=0;i<n;i++){
            map.insert({ans[i],sum});
            sum += ans[i];
        }
        vector<long long> res;
        for(int i=0;i<n;i++){
            res.push_back(map[arr[i]]);
            
        }
        return res;
    }
};

//{ Driver Code Starts.

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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends