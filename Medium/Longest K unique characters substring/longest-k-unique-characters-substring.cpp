//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i = 0,q=k,n = s.length(),j=0,ans=-1;
        vector<int> a(26,0);
        while(i<n){
            while(i<n && (q>0||a[s[i]-97]>0)){
                if(a[s[i]-97]==0)q-=1;
                a[s[i]-97]+=1;
                i+=1;
            }
            if(q==0)
            ans = max(ans,i-j);
            while(j<i && q==0){
                a[s[j]-97]-=1;
                if(a[s[j]-97]==0){q+=1;j+=1;break;}
                j+=1;
            }
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends