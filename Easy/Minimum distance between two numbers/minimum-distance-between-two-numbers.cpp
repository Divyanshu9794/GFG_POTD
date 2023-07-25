//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int ans=n+2;
        int i=0;int j=1;
        while(i<n and j<n)
        {
            if(a[i]!=x)i++;
            if(a[j]!=y)j++;
           if(a[i]==x and a[j]==y)
           {
               int dis=abs(j-i);
               ans=min(ans,dis);
               if(i>j)j++;
               else i++;
           }

        }
        if(ans==n+2)return -1;
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
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends