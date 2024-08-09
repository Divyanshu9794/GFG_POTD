//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long M = 1000000007;
    int Maximize(vector<int> a){
        long long sum=0;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            sum+=(a[i]%M*i%M)%M;
        }
        return sum%M;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends