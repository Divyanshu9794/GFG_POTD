//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            
            int dotc=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    dotc++;
                }
            }
            if(dotc!=3){
                return 0;
            }
            dotc=0;
            unordered_set<string> st;
            for(int i=0;i<256;i++){
                st.insert(to_string(i));
            }
            string t="";
            for(int i=0;i<s.size();i++){
                if(s[i]!='.'){
                    t+=s[i];
                }
                else{
                    if(st.count(t)!=0){
                        dotc++;
                    }
                    t="";
                }
            }
            if(st.count(t)!=0){
                dotc++;
            }
            if(dotc==4){
                return 1;
            }
            return 0;
        }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends