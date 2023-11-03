//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int maxi=arr[0];
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,arr[i]);
	    }
	    
	    int arr1[maxi+1]={0};
	    
	    for(int i=0;i<n;i++)
	    {
	       arr1[arr[i]]=1; 
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            double m = sqrt((arr[i]*arr[i])+(arr[j]*arr[j]));
	            
	            if(m==floor(m) && arr1[int(m)]==1)
	            return true;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends
