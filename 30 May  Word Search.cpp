class Solution {
public:
    void check(vector<vector<char>>& board,int i,int j,int &flag,string word,int h)
    {
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0)
        return;
        
        if(word.length()<=h)
        {
            flag=1;
            return;
        }
        if(board[i][j]!=word[h])
        return;
        else
        {
            board[i][j]='9';
            h++;
        
            check(board,i+1,j,flag,word,h);
            check(board,i-1,j,flag,word,h);
            check(board,i,j+1,flag,word,h);
            check(board,i,j-1,flag,word,h);
        }
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int flag=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    check(board,i,j,flag,word,0);
                }
                if(flag==1)
                return true;
            }
        }
        return false;
    }
};
