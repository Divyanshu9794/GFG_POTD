//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int longestSubsequence(int n, int a[])
    {
       
      vector<int> temp;
      temp.push_back(a[0]);
      int ans=1;
      for(int i=0;i<n;i++){
          if(a[i]>temp.back()){
              temp.push_back(a[i]);
              ans++;
          }
          else{
              int ind=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
              temp[ind]=a[i];
          }
      }
      return ans;
    }
	int minDeletions(int arr[], int n) 
	{ 
	    return n-longestSubsequence(n,arr);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends