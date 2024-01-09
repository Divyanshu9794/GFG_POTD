//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int > mp;
	    int s=0,mx=0;
	    mp[0]=-1;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	        int r=s%k;
	        if(r<0){
	            r+=k;
	        }
	        if(mp.find(r)==mp.end()){
	            mp[r]=i;
	        }
	        mx=max(mx,i-mp[r]);
	    }
	    return mx;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends