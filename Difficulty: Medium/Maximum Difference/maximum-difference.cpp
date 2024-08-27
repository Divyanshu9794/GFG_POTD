//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        vector<int>left ;
        vector<int>right ;
        
        int n = arr.size() ;
        
        left.push_back(0);
        int l = arr[0];
        
        for(int i = 1 ; i < n ;i++)
        {
            if(l < arr[i]){
                left.push_back(l);
            }
            else if(left[i-1] < arr[i]){
                left.push_back(left[i-1]);
            }
            else
            {
                int j = i-1;
                while(j >= 0 && left[j] >= arr[i])
                {
                    j--;
                }
                
                left.push_back(left[j]);
                
            }
            l = arr[i];
        }
        
        right.push_back(0);
        
        int r = arr[n-1];
        int index = 0;
        
        for(int i = n-2 ; i >= 0 ;i--)
        {
            if(r < arr[i]){
                right.push_back(r);
            }
            else if(right[index] < arr[i]){
                right.push_back(right[index]);
            }
            else
            {
                int j = index;
                while(j >= 0 && right[j] >= arr[i])
                {
                    j--;
                }
                if(j >= 0){
                    right.push_back(right[j]);
                }
                
            }
            r = arr[i];
            index++;
        }
        
        reverse(right.begin() ,right.end());
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(abs(left[i] - right[i]) > ans){
                ans = abs(left[i] - right[i]);
            }
        }
        
        return ans ;
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends