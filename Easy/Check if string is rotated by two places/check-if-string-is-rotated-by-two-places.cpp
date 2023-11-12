//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n1 = str1.length();
         int n2 = str2.length();
         if(n1 != n2)  return false;
         if(n1 == 1 && n2 == 1) {
            if(str1 != str2)
                return 0; }
         str1 = str1 + str1;
        int found = str1.find(str2);
         if(found == 2 || found == n1-2 )
            return true;
      return false;
    }

};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends