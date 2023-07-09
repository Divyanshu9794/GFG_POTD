//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        //
        string commPre = arr[0]; 
        //
        for(int i=1; i<N; i++){
            
            string curr = arr[i];
            int len = min(commPre.length(), curr.length());
            int j = 0;
            
            while(j < len){
                if(commPre[j] != curr[j]) break;
                j += 1;
            }
            
            commPre = commPre.substr(0, j);
        }
        
        //
        return (commPre == "")? "-1" : commPre;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends