//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
     int minOperation(int n)
    {
        
        int ans=0;
         if(n==1 || n==0){
            return ans+1;
        }
        if(n%2==0){
           ans=1+minOperation(n/2);
        }
        else{
            ans=1+minOperation(n-1);
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends