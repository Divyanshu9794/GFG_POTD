//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     long long int solve(string s,int k){
        int i = 0;
        int j = 0 ;
        int n = s.length() ; 
        vector<int>charFreq(26,0); 
        int dist_count = 0 ;
        long ans = 0 ;
        while(j<n){
            charFreq[s[j]-'a']++;
            if(charFreq[s[j]-'a']==1){
                dist_count++;
            }
            while(dist_count>k){
                charFreq[s[i]-'a']--;
                if(charFreq[s[i]-'a']==0){
                    dist_count--;
                }
                i++;
            }
            j++;
            ans+=(j-i+1) ; 
        }
        return ans ;
    }
    long long int substrCount(string S, int K) {
        return solve(S,K)-solve(S,K-1) ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends