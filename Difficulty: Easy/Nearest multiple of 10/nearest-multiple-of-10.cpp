//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        string ans="";
            int ele=10-(str.back()-'0');
        if(str.back()-'0'>5){
            int carry=0;
            for(int i=str.length()-1;i>=0;i--){
                int num=str[i]-'0';
                int sum=num+ele+carry;
                ans=to_string(sum%10)+ans;
                carry=sum/10;
                ele=0;
            }
        }
        else{
            ans=str;
            ans[str.length()-1]='0';
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends