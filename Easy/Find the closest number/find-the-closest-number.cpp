//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
      int findClosest( int n, int k,int arr[]) 
    { 
        auto it1 = upper_bound(arr,arr+n,k);
        if(it1 == arr) return arr[0];
        auto it2 = prev(it1);
        if(*it1 - k > k-*it2) return *it2;
        return *it1;
    }  
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends