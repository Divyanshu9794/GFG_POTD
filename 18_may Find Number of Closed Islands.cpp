class Solution 
{
    bool check(vector<vector<int>>& matrix, int r, int c)
    {
        if (r < 0 or r == matrix.size() or c < 0 or c == matrix[0].size() 
        or matrix[r][c] == 0) return false;
        return true;
    }
    public:
    void dfs(vector<vector<int>>& matrix, int r, int c) 
    {
        if(check(matrix, r, c) == false) return;
        
        matrix[r][c] = 0;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int i = 0; i < 4; i++)
        {
            dfs(matrix, r + dx[i], c + dy[i]);
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        for(int r = 0; r < N; r++) 
        {
            for(int c = 0; c < M; c++) 
            {
                if (r == 0 or r == N - 1 or c == 0 or c == M - 1) 
                {
                    dfs(matrix, r, c);
                }
            }    
        }     
        int cnt = 0;
        for(int r = 0; r < N; r++) 
        {
            for(int c = 0; c < M; c++) 
            {
                if (matrix[r][c] == 1) 
                {
                    cnt++;
                    dfs(matrix, r, c);
                }
            }
        }
        return cnt;
    }
};
