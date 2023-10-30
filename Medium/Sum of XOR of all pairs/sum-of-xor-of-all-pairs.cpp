//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        //Complete the function
        long long int ans=0;
    
        
        for(int i=0;i<32;i++)
        {
            long long int cnt1=0,cnt0=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]&1) cnt1++;
                else cnt0++;
                arr[i]=arr[i]>>1;
            }
            long long int z=(cnt1)*(cnt0);
            ans=ans+z*(1<<i);
            
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends