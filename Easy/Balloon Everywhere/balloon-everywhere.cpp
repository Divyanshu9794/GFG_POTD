//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int bc=0,ac=0,lc=0,oc=0,nc=0,otc=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                bc++;
            }
            else if(s[i]=='a'){
                ac++;
            }
            else if(s[i]=='l'){
                lc++;
            }
            else if(s[i]=='o'){
                oc++;
            }
            else if(s[i]=='n'){
                nc++;
            }
            else{
                otc++;
            }
        }
        int x=min(bc,min(ac,nc));
        int y = min(lc,oc);
        if(2*x>=y){
            return y/2;
        }
        else{
            return x;
        }
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
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends