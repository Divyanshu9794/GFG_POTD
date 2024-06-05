//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1=0,sum2=0,diff=0;
        sort(a,a+n);
        for(int i=0;i<n;i++) sum1+=a[i];
        for(int i=0;i<m;i++) sum2+=b[i];
        diff=sum1-sum2;
        if((sum1+sum2)&1 or abs(diff)&1)
            return -1;
        for(int i=0;i<m;i++){
            if(binary_search(a,a+n,diff/2+b[i]))
                return 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends