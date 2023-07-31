//{ Driver Code Starts
#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h> 
using namespace std;  

// } Driver Code Ends

class Solution{
    public:
    /*You are requried to complete this method */
    int max_Books(int a[], int n, int k)   //// EASY CODE////
    {
       
        if(a[0] > k) a[0]=0;
        for(int i=1;i<n;i++){
            if(a[i] <= k) a[i]=a[i]+a[i-1];
            else a[i]=0;
        }
        
        int maxt=0;
        
        for(int i=0;i<n;i++){
            maxt = max(maxt,a[i]); 
        }
        
        return maxt;
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
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
  	Solution ob;
  	cout<<ob.max_Books(ar,n,k)<<endl;
        
  }    
  return 0;
}


// } Driver Code Ends