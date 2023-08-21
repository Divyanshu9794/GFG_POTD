//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int a[], int n) {
        vector<int> ans;
        int carry = 0, sum = 1 + a[n - 1];
        a[n - 1] = sum % 10;
        carry = sum / 10;
        
        int i = n - 2;
        while(i >= 0 and carry) {
            sum = a[i] + carry;
            a[i] = sum % 10;
            carry = sum / 10;
            i--;
        }
        
        if(carry) ans.push_back(carry);
        
        for(int i = 0; i < n; i++)
            ans.push_back(a[i]);
            
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends