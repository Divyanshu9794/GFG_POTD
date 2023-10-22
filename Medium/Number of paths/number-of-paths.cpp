//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    #define MOD (int)(1e9+7)
    long long BinExp(int base,int power)
    {
        long long ans=1;
        while(power)
        {
            if(power&1) ans=(ans*base)%MOD;
            base=(base*1LL*base)%MOD;
            power>>=1;
        }
        return ans;
    }
    long long  numberOfPaths(int m, int n)
    {
        // (m+n-2) C (n-1)
        // = (m+n-2)! / (n-1)! *(m-1)!
        
        long long num=1;
        for(int i=n;i<=m+n-2;i++) num=(num*i)%MOD;
        
        long long den=1;
        for(int i=1;i<=m-1;i++) den=(den*i)%MOD;
        
        return (num*BinExp(den,MOD-2))%MOD;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends