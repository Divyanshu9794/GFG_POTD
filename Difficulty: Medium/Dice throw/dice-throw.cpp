class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int tar=0;tar<=x;tar++){
                int sum=0;
                for(int j=1;j<=m;j++){
                    if(j<=tar) sum+=dp[i+1][tar-j];
                    }
                dp[i][tar]=sum;
            }
        }
        return dp[0][x];   
    }
};