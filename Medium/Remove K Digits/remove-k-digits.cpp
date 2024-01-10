//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        int n=s.size();
        for(auto it:s){
            while(!st.empty() and st.top() > it and k>0){
                st.pop();
                k--;
            }
            if(!st.empty() or it!='0'){
                st.push(it);
            }
        }
        while(!st.empty() and k--){
            st.pop();
        }
        
        if(st.empty()) return "0";
         
         while(!st.empty()){
             s[n-1]=st.top();
             st.pop();
             n--;
         } 
         return s.substr(n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends