//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> printMissingIntervals(int a[], int n) {
       vector<int>ans;
        int st=0,et=99999;
        for(int i=0;i<n;i++){
            if(a[i]!=st){
                ans.push_back(st);
                ans.push_back(a[i]-1);
            }
            st=a[i]+1;
        }
        if(a[n-1]!=et){
            ans.push_back(a[n-1]+1);
            ans.push_back(99999);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int a[n];
        for(int i=0 ; i<n ; i++)
            cin>>a[i];

        Solution ob;
        vector<int> vec = ob.printMissingIntervals(a,n);
        
        for(int i=0 ; i<vec.size() ; i+=2)
        {
            if (vec[i]==vec[i+1])
                cout<<vec[i];
            else
                cout<<vec[i]<<"-"<<vec[i+1];
            if(i!=vec.size()-2)
                cout<<",";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends