//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<=k;i++){
            mp[arr[i]]++;
           // cout<<arr[i]<<endl;
            if(mp[arr[i]]>1) return true;
           // cout<<i<<endl;
        }
         for(int i=k+1;i<n;i++){
            mp[arr[i]]++;
            mp[arr[i-k-1]]--;
            if(mp[arr[i-k-1]]==0) mp.erase(mp[arr[i-k]]);
            if(mp[arr[i]]>1) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends