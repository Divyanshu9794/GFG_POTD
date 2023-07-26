//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

vector<int> bracketNumbers(string str)
    {
      int temp=1;
      vector<int> res;
    stack<pair<char,int>> st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            pair<char,int> p;
            p=make_pair(str[i],temp);
            st.push(p);
            res.emplace_back(temp);
            temp++;
        }
        else if(str[i]==')')
        {
             if(st.top().first=='(')
             {
               res.emplace_back(st.top().second);
                st.pop();
             }
        }
    }
    return res;
    }
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.bracketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends