//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
     string largestNumber(int n, int sum)
    {
       
       if(n*9<sum){
           return "-1";
       }
       
        int a=sum/9;
        int b=sum%9;
        string s;
        for(int i=0;i<a;i++){
            s=s+'9';
        }
        if(a*9!=sum){
        s=s+to_string(b);    
        }

        while(s.length()!=n){
            s=s+'0';
        }
        
        return s;
    }

 
};

//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends