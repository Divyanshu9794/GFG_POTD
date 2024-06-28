//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

      bool palindromeRow(vector<vector<int>> &arr , int ind)
    {
        int i = 0 , j = arr[0].size() - 1;
        while(i < j)
        {
            if(arr[ind][i] != arr[ind][j])
            return false;
            
            i++;j--;
        }
        return true;
    }
    bool palindromeCol(vector<vector<int>> &arr , int ind)
    {
        int i = 0 , j = arr.size() - 1;
        while(i < j)
        {
            if(arr[i][ind] != arr[j][ind])
            return false;
            
            i++;j--;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        int row =-1 , col =-1;
        for(int i = 0 ; i < n  ; i++)
        {
            if(row == -1 && palindromeRow(arr , i))
            row = i ; 
            if(col == -1 && palindromeCol(arr , i))
            col = i ;
        }
        if(row != -1)
        return to_string(row) + " R";
        else if(col != -1)
        return to_string(col) + " C";
        else
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends