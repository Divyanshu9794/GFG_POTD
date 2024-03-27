//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     int findShortestPath(vector<vector<int>> &mat)
    {
      
      int ans=INT_MAX;
      
      int n=mat.size();
      int m=mat[0].size();
      
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(mat[i][j]==0)
              {
                  int x[4]={0,0,1,-1};
                  int y[4]={1,-1,0,0};
                  
                  for(int k=0;k<4;k++)
                  {
                      int nx=i+x[k];
                      int ny=j+y[k];
                      
                      if(nx>=0 && nx<n && ny>=0 && ny<m)
                      {
                          if(mat[nx][ny]!=0)
                            mat[nx][ny]=-2;
                      }
                  }
              }
          }
      }
      
      for(int i=0;i<n;i++)
      {
          queue<pair<pair<int,int>,int>> q;
          map<pair<int,int>,int> mp;
          
          if(mat[i][0]==1)
            q.push({{i,0},1});
          
          mp[{i,0}]=1;
          
          while(!q.empty())
          {
              int id=q.front().first.first;
              int jd=q.front().first.second;
              int count=q.front().second;
              
              int x[4]={0,1,-1,0};
              int y[4]={1,0,0,-1};
              
              q.pop();
              
              if(jd==m-1)
              {
                  ans=min(ans,count);
                  
              }
              else
              {
              
                  for(int j=0;j<4;j++)
                  {
                      int nx=id+x[j];
                      int ny=jd+y[j];
                      
                      if(nx>=0 && nx<n && ny>=0 && ny<m && mp[{nx,ny}]==0 && mat[nx][ny]==1)
                      {
                         q.push({{nx,ny},1+count});
                         mp[{nx,ny}]=1;
                      }
                      
                  }
              }
          }
      }
      
      if(ans==INT_MAX)return -1;
      
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends