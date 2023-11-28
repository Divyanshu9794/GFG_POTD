//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    void sortABS(int A[],int N, int k)
    {
       vector<pair<int,int>>v;
      for(int i=0;i<N;i++)
      {
    v.push_back(make_pair(abs(A[i]-k),i));
      }
      sort(v.begin(),v.end());
      int B[N];
      for(int i=0;i<N;i++)
      {
    B[i]=A[v[i].second];
      }
      for(int i=0;i<N;i++)
      {
        A[i]=B[i];
      }
    }

};


//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends