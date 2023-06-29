//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string>st;
	    void findi(int i,int j,string s, string t,string &temp,vector<string>&ans,int lcslen){
	        if(lcslen==0){
	            if(st.find(temp)==st.end()){
	                st.insert(temp);
	                ans.push_back(temp);
	            }
	            return;
	        }
	        if(i>=s.size() || j>=t.size())return;
	        for(int r=i;r<s.size();r++){
	            for(int c=j;c<t.size();c++){
	                if(s[r]==t[c]){
	                    temp.push_back(s[r]);
	                    findi(r+1,c+1,s,t,temp,ans,lcslen-1);
	                    temp.pop_back();
	                }
	            }
	        }
	    }
	   
	
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int n1=s.size();
            int n2=t.size();
            vector<int>prev(n2+1,0),curr(n2+1,0);
            for(int i=0;i<=n2;i++)prev[i]=0;
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(s[i-1]==t[j-1]){
                        curr[j]=1+prev[j-1];
                    }
                    else curr[j]=max(prev[j],curr[j-1]);
                }
                prev=curr;
            }
            int lcslen=prev[n2];
            vector<string>ans;
            string temp="";
            findi(0,0,s,t,temp,ans,lcslen);
            sort(ans.begin(),ans.end());
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends