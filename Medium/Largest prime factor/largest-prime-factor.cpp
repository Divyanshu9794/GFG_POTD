//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
         int ans=-1;
        int i=2;
        while(i*i<=N){
            while(N%i == 0){
                ans = i;
                N= N/i;
            }
            i+= 1;
        }
        if(N > 1) ans = N;
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends