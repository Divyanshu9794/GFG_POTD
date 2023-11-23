//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long

class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> res;
        res.push_back(1);
        vector<long long> temp;
        
        long long mod = 1e9+7;
        
        for(int i=1;i<n;i++){
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back((res[j-1]+res[j])%mod);
            }
            temp.push_back(1);
            
            res = temp;
            temp.clear();
        }
        return res;
    
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends