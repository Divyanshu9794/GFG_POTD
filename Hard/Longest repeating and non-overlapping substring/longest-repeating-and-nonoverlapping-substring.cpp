//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string ans="";
        for(int st=0;st<n;st++){
        string pat=s.substr(st,n-st);
        vector<int> lps(pat.size(),0);
        int i=1;int len=0;
        while(i<pat.size()){
            if(pat[i]==pat[len]){
                len++;lps[i]=len;i++;
            }
            else{
                if(len==0){lps[i]=0;i++;}
                else len=lps[len-1];
            }
        }
         int maxlen=0;
         for(int i=0;i<lps.size();i++){
             if(lps[i]<=(i+1)/2){
                 maxlen=max(maxlen,lps[i]);
             }
             else{
                 int common=(2*lps[i])-(i+1);
                 maxlen=max(maxlen,min(common,(i+1)/2));
             }
         }
         if(maxlen>ans.size()){
             ans=pat.substr(0,maxlen);
         }
        }
        if(ans=="") return "-1";
        else
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends