//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {

        int ans=0;
        int i=0;


        if(s[i] == '-'){
            i++;
        }


        for(; i<s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ans *= 10;
                ans += (s[i] - '0');
            }
            else{
                return -1;
            }
        }


        if(s[0] == '-'){
            ans *= -1;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends