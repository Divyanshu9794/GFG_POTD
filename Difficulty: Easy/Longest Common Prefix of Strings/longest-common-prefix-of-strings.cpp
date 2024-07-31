//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int mini = INT_MAX;
        string ans;
        bool flag = false;
        for(int i=0;i<arr.size();i++){
            int l = arr[i].length();
            mini = min(mini,l);
        }
        for(int i=0;i<mini;i++){
            char c = arr[0][i];
            for(int j=1;j<arr.size();j++){
                if(arr[j][i]!=c){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans+=c;
            }
            else{
                if(ans.length() == 0){
                   return "-1";
                }
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends