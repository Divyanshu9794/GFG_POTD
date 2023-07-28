//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

		
class Solution{
public:	
	int isSame(string s)
	{
	    // Your code goes here
	    int i = 0;
	    int count = 0;
	    int n = s.length();
	    while(i < n && !(s[i] >= '0' && s[i] <= '9')){
	        i++;
	        count++;
	    }
	    int num = 0;
	    while(i < n){
	        num = num*10 + s[i++] - '0';
	    }
	    if(num != count){
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isSame(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends