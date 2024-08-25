//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        vector<double> a(arr.size());
        for(int i=0;i<arr.size();i++){
            a[i]=pow(arr[i],1.0/arr[i]);
        }
        vector<double> b(brr.size());
        for(int i=0;i<brr.size();i++){
            b[i]=pow(brr[i],1.0/brr[i]);
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int n=b.size();
        int c=0;
        long long ans=0;
        
        for(int i=0;i<a.size();i++){
            
            while(c<n && a[i]>b[c]){
                c++;
            }
            ans+=c;
            
        }
        
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends