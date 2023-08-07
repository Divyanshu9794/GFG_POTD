//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool issafe(int r,int c,int grid[N][N],int val){
        for(int i=0;i<N;i++){
            if(grid[r][i]==val){
                return false;
            }
            if(grid[i][c]==val){
                return false;
            }
            if(grid[3*(r/3)+i/3][3*(c/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                if(grid[r][c]==0){
                    for(int val=1;val<=9;val++){
                        if(issafe(r,c,grid,val)){
                            grid[r][c]=val;
                            bool ispossible =  SolveSudoku(grid);
                            if(ispossible){
                                return true;
                                
                            }
                            else{
                                grid[r][c ]=0;
                                
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid); 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends