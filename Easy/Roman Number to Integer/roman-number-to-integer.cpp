//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int>mp;

      int ans=0;

      mp['I']=1;

      mp['V']=5;

      mp['X']=10;

      mp['L']=50;

      mp['C']=100;

      mp['D']=500;

      mp['M']=1000;

      for(int i=str.size()-1;i>=0;i--){

       if(mp[str[i-1]]<mp[str[i]]&&i<str.size()){

           ans+=mp[str[i]]-mp[str[i-1]];

           i=i-1;

       }

       else ans+=mp[str[i]];

      }

      return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends