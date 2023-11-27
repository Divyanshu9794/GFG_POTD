//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string BoomNumber(long long int k) {
    
        long long int rem;
        int len;
        string str="",fin="";
        
        if(k==1)
        return("2");
        if(k==2)
        return ("3");
        
        k++;
        while(k>0)
        {
            rem=k%2;
            k=k/2;
            str=str+((char) (rem+48)); 
        }
        
        len=str.length();
        len--;
        for(int i=len-1;i>=0;i--)
        {
            fin=fin+(char) (2+(int) (str.at(i)));
        }
        return (fin);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int K;
        cin >> K;
        Solution ob;
        cout << ob.BoomNumber(K) << endl;
    }
    return 0;
}

// } Driver Code Ends