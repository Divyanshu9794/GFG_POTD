//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

        bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<int> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
           
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i] = ans;
    }
    

    int palindromicPartition(string s)
    {
        int n = s.length();
       
        vector<int> dp (n+1, -1);   
            
        return solve (s, 0, n-1, dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends