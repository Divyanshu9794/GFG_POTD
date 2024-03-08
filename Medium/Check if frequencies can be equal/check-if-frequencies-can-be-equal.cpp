//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    int arr[26];
	    memset(arr,0,sizeof(arr));
	    set<char> st;
	    int maxFreq = INT_MIN;
	    for(char c : s){
	        arr[c-'a']++;
	        st.insert(c);
	        maxFreq = max(maxFreq, arr[c-'a']);
	    }
	    
	    if(((maxFreq -1)*st.size() == s.length() - 1) || ((maxFreq * st.size()) == s.length() ) )  return 1;
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends