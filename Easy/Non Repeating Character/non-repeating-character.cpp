//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
        vector<int> mp(26,0);
       int n= s.length();
      for(int i = 0 ; i<n ;i++)
      {
          mp[s[i]-'a']++;
      }
      for(int i = 0 ; i<n ;i++)
      {
          if(mp[s[i]-'a']==1)
            return s[i];
      }
      
      return '$';
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends