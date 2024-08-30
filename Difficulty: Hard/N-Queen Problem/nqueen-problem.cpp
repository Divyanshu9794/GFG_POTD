//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    
    //checking int same row
    for(int i = col; i>=0; i--){
        if(board[row][i] == 1){
            return false;
        }
    }
    
    //Checking in upper diagonal
    int i = row;
    int j = col;
    
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    
    //Checking in Lower diagonal
    i = row;
    j = col;
    
    while(i < n && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

void solve(vector<vector<int>> &board, int n, int col, vector<vector<int>> &ans, vector<int> temp){
    
    if(col == n){
        ans.push_back(temp);
        return;
    }
    
    //Trying all possible rows
    for(int row = 0; row < n; row++){
        if(isSafe(board, row, col, n)){
            
            temp.push_back(row+1);
            board[row][col] = 1;
            
            solve(board, n, col+1, ans, temp);
            
            board[row][col] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<int>> nQueen(int n) {
    
    vector<vector<int>> board(n, vector<int> (n, 0));
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    solve(board, n, 0, ans, temp);
    
    return ans;
}

};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends