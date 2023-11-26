//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int carry=0;
	    string ans="";
	    int i=A.size()-1,j=B.size()-1;
	    while(i>=0 and j>=0)
	    {
	        int t=(A[i]-'0')+(B[j]-'0')+carry;
	        int rem=t%2;
	        carry=t/2;
	        ans+=(rem+'0');
	        i--;j--;
	    }
	    while(i>=0)
	    {
	      int t=(A[i]-'0')+carry;
	        int rem=t%2;
	        carry=t/2;
	        ans+=(rem+'0');
	        i--;  
	    }
	    while(j>=0)
	    {
	        int t=(B[j]-'0')+carry;
	        int rem=t%2;
	        carry=t/2;
	        ans+=(rem+'0');
	        j--;
	    }
	    if(carry)
	    {
	        ans+=(1+'0');
	    }
	    reverse(ans.begin(),ans.end());
	
	    while(ans[0] == '0') ans.erase(ans.begin());
        return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends