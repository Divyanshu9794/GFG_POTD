//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) 
    {
       
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        
        int ans=-1;
        int lstind=0;
        
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j]  && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                    
                    if(ans<dp[i])
                    {
                        lstind=i;
                        ans=dp[i];
                    }
                }
            }
        }
         
        vector<int> s;
        s.push_back(arr[lstind]);
        
        while(hash[lstind]!=lstind)
        {
            lstind=hash[lstind];
            s.push_back(arr[lstind]);
        }
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends