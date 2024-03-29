//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long M = 1000000007;
    int Maximize(int a[],int n){
        long long sum=0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            sum+=(a[i]%M*i%M)%M;
        }
        return sum%M;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends