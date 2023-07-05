//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int toyCount(int n, int sum, vector<int> cost)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
    
        int res=0;
        for(int i=0;i<n;i++)
            pq.push(cost[i]);
        
        for(int i=0;i<n;i++){
            if(pq.top()<=sum){
                sum-=pq.top();
                pq.pop();
                res++;
            }else{
                break;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends