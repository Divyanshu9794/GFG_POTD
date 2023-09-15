//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void subSetSum(int i,vector<int> arr,int n,int sum,vector<int> &ans){
        if(i==n){
           ans.push_back(sum); 
           return;
        }
        
        subSetSum(i+1,arr,n,sum+arr[i],ans);
        
        subSetSum(i+1,arr,n,sum,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        
        vector<int> ans;
        int sum=0;
        subSetSum(0,arr,N,sum,ans);
     
        sort(ans.begin(),ans.end());
        return ans;
    }


};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends