//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
		    vector<string>ans;
    string x="";
        void solve(int i,string s)
        {
            int n=s.size();
            if(i==n)return ;
            x+=s[i];
            if(x.size()>0)
            ans.push_back(x);
            solve(i+1,s);
            x.pop_back();
            solve(i+1,s);
        }
        vector<string> AllPossibleStrings(string s){
         solve(0,s);
         sort(ans.begin(),ans.end());
         return ans;
        }
		
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends