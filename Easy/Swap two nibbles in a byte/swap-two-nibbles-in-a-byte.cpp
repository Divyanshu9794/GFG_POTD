//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int swapNibbles(int n) {
        // code here
        bitset<8> dtob(n);
        string str=dtob.to_string();
        for(int i=0;i<4;i++){
            swap(str[i],str[i+4]);
        }
        string str2="";
        for(int i=0;i<8;i++){
            str2+=str[i];
        }
        // cout<<str2;
        unsigned long ans=stoul(str2,nullptr,2);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends