//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    bool vowel(char i){
        if(i=='a' || i=='e'|| i=='o' || i=='u' || i=='i'){
            return true;
        }
        return false;
    }
    public:
    string Sandwiched_Vowel(string s){
        string ans= "";
        for(int i=0; i<s.size(); i++){
            if(vowel(s[i]) && !vowel(s[i-1]) && !vowel(s[i+1]) && i!=0 && i!=s.size()-1){
                continue;
            }
            ans=ans+s[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        string ans = obj.Sandwiched_Vowel(s);
        cout<<ans<< endl;
    }

	return 0;
}
// } Driver Code Ends