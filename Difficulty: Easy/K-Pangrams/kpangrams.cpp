//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int len_str=0;
        
        unordered_map<char,int> mpp;
        for(auto ch : str){
            if(ch != ' '){
                mpp[ch]++;
                len_str++;
            }
        }
        
        if(len_str < 26)  // case where total char are less than 26
            return false;
            
        if(mpp.size()==26) // case where a to z are present
            return true;
            
        int req_chng = 26 - mpp.size();
        
        if( req_chng <= k) 
            return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends