//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum){
         string s(n,'0');
        
        if(sum==0 and n==1) return "0";
        if(sum==0) return "-1";
        
        int check=sum;
        
        int i=0;
        while(i<n){
            
            if(sum>9){
                s[i]='9';
                sum-=9;
            }else if(sum>=0 and sum<=9){
                s[i]= sum + '0';
                return s;
            }
            i++;
        }
        
        return sum>0? "-1":s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends