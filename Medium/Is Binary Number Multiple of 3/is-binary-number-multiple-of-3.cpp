//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int oddnum=0,evennum=0;
	    for(int i=0;i<s.size();i++){
	        if(i%2==0 and s[i]=='1')evennum++;
	        else if(i%2==1 and s[i]=='1')oddnum++;
	    }
	    if(abs(evennum - oddnum)%3==0){
	        return 1;
	    }
	    return 0;
	}


};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends