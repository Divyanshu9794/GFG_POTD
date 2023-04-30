//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
       int maxi = 0;
        for(int i = 0;i < n;i++)
        {
            maxi = max(maxi,intervals[i][1]);
        }
        vector <int> ran(maxi + 2 , 0);
        for(int i = 0;i < n;i++)
        {
            ran[intervals[i][0]]++;
            ran[intervals[i][1] + 1]--;
        }
        int ele = -1;
        int oc = -1;
        int sum = 0;
        for(int i = 0;i < maxi + 2 ;i++)
        {
            sum += ran[i];
            if(sum >= k)
            {
                ele = i;
            }
        }
        return ele;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends