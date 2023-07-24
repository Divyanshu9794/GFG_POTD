//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*The function returns an integer
which denotes the max value 
of abs(i â€“ j) * min(arr[i], arr[j]) 
in the array.
*/

/*You are required to complete this method*/
class Solution
{
    public:
    int max_val(int arr[], int n)
    {
        int s  =0; 
        int e = n-1;
        int maxi =INT_MIN;
        int ans;
        while(s<e){
            ans = abs(s-e)*min(arr[s],arr[e]); 
            maxi = max(maxi,ans); 
            if(arr[s]<arr[e])
            s++;
            else
            e--;
        }
        return maxi;
    }
};

//{ Driver Code Starts. 

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		Solution ob;
		cout<<ob.max_val(a,n)<<endl;
		
	}
	return 0;
}
// } Driver Code Ends