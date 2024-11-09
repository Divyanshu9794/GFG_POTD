//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string addString(string s1,string s2){
      int i = s1.size()-1 ,j= s2.size()-1;
      string ans = "";
      int carry = 0;
      while(i>=0 || j>=0 || carry){
          int a = 0 , b = 0 ;
          if(i>=0) a = s1[i]-'0';
          if(j>=0) b = s2[j]-'0';
          int sum = a+b+carry;
          int digit = sum%10;
          carry =sum/10;
        if(sum) ans.push_back('0'+digit);
          i--;j--;
      }
      reverse(ans.begin(),ans.end());
      return ans;
  }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string s1 = "" ,s2 ="";
        for(int i =0;i<arr.size();i++){
            if(i&1) s2.push_back('0'+arr[i]);
            else s1.push_back('0'+arr[i]);
        }
        return addString(s1,s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends