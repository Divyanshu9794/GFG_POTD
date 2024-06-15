//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        vector<vector<int>>neighbours={{8},{2,4},{1,3,5},{2,6},{1,5,7},{2,4,6,8},{3,5,9},{4,8},{5,7,9,0},{6,8}};
        vector<long long>ans(10,1);
        for(int i=1;i<n;i++){
            vector<long long>cur=ans;
            for(int j=0;j<10;j++){
                cur[j]=ans[j];
                for(int nbr:neighbours[j]){
                    cur[j]+=ans[nbr];  
                }
            }
            ans=cur;
        }
        long long res=0;
        for(int i=0;i<10;i++){
            res+=ans[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends