//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code herech
        stack<char>st;
        int n=x.size();
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                st.push(x[i]);
            }
            else{
                if((!st.empty() && x[i]==')' && st.top()=='(') || (!st.empty() && x[i]==']' && st.top()=='[')  || (!st.empty() && x[i]=='}' && st.top()=='{')){
                    st.pop();
                }
                else return false;
            }
        }
        
        if(st.empty())return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends