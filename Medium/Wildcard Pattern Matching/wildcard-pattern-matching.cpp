//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

int f(int i,int j,string &pattern, string &text,vector<vector<int>> &dp){
   if(i<0 && j<0){
      return 1;
   }
   if(i<0 && j>=0){
      return 0;
   }
   if(j<0 && i>=0){
      for(int ii = 0;ii<=i;ii++){
         if(pattern[ii]!='*'){
            return 0;
         }
      }
      return 1;
   }
   if(dp[i][j]!=-1){
      return dp[i][j];
   }
   if(pattern[i]==text[j] || pattern[i]=='?'){
      return dp[i][j]=f(i-1,j-1,pattern,text,dp);
      
   }
   if(pattern[i]=='*'){
      return dp[i][j] = f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
   }
   return dp[i][j]= 0;
}

int wildCard(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>> dp(n,vector<int>(m,-1));
   return f(n-1,m-1,pattern,text,dp);
   
}
    
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends