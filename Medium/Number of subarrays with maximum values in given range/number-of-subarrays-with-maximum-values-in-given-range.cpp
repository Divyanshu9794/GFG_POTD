//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int l, int r)
    {
        long x{}, y{};
        
        for(long i{}, j{}; j < n; j++) {
            if(a[j] >= l and a[j] <= r) y = j - i + 1;
            else if(a[j] > r) y = 0, i = j + 1;
            x += y;
        }
        
        return x;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends