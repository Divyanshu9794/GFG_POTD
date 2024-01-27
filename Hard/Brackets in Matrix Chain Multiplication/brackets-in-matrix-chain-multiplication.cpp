//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef pair<string,int> pi;
class Solution{
    public:
    pi help(int* p,int i,int j,vector<vector<pi>>& memo)
    {
        //base case
        if(i==j)
        {
            string s="";
            s+='A'+i-1;
            return {s,0};
        }
        
        //memo check
        if(memo[i][j].second!=-1)
        return memo[i][j];
        
        // recursive calls
        // and small calculation
        int mini=1e9;
        string st="";
        for(int ind=i;ind<j;ind++)
        {
            auto left=help(p,i,ind,memo);
            auto right=help(p,ind+1,j,memo);
            int cal=p[i-1]*p[ind]*p[j]+left.second+right.second;
            
            if(cal<mini)
            {
                mini=cal;
                string s="("+left.first+right.first+")";
                st=s;
            }
        }
        return memo[i][j]={st,mini};
    }
    string matrixChainOrder(int p[], int n){
        vector<vector<pi>> memo(n,vector<pi>(n,{"",-1}));
        return help(p,1,n-1,memo).first;
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends