//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    string roundToNearest(string N) 
    { 
        int n = N.size();
        if(n==1 && N <="5") return "0";
        if(n==1 && N >"5") return "10";
        
        if(N[n-1]<='5'){
            N[n-1]='0';
            return N;
        } 
        N[n-1]='0';
        int carry=1;
        for(int i=n-2;i>=0;i--){
            carry=(N[i]-'0')+carry;
           
            if(carry<10){
                 N[i]=(carry%10)+'0';
                 
            }
            else{
                 N[i]=(carry%10)+'0';
            }
            carry/=10;
            
        }
        if(carry>0) N = "1"+N;
        
        
        return N;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }
    
	return 0;
}
// } Driver Code Ends