//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>> ans;
    bool palindrome(string a){
        int n = a.size();
        for(int i=0;i<(n/2);i++){
            if(a[i]!=a[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void find(string s,int i,vector<string> v)
    {
        if(i>=s.size()){
            ans.push_back(v);
            return ;
        }

        string a = "";
        for(int k=i;k<s.size();k++){
            a+=s[k];
            if(palindrome(a)){
                v.push_back(a);
                find(s,k+1,v);
                v.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        find(S,0,{});
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends