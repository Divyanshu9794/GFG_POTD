class Solution {
  public:
    
    int n;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,-1,1,0};
    
    bool check(int i,int j){
        return i<n && j<n && i>=0 && j>=0;
    }
    
    void find(int i,int j,vector<vector<int>>& maze,string &temp,vector<string>&ans,int &n){
        
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        maze[i][j]=0;
        
        for(int k=0;k<4;k++){
            
            if(check(i+row[k],j+col[k]) && maze[i+row[k]][j+col[k]]){
                if(k==0)temp.push_back('D');
                else if(k==1)temp.push_back('L');
                else if(k==2)temp.push_back('R');
                else temp.push_back('U');
                find(i+row[k],j+col[k],maze,temp,ans,n);
                temp.pop_back();
            }
            
        }
        
        maze[i][j]=1;
        return;
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze.size();
        if(maze[n-1][n-1]==0 && maze[0][0]==0)return {};
        
        //vector<vector<bool>>visited(n,vector<bool>(n,1));
        string temp="";
        vector<string>ans;
        
        find(0,0,maze,temp,ans,n);
        
        return ans;
        
    }
};