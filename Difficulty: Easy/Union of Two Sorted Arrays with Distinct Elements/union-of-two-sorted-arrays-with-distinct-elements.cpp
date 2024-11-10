//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
         vector<int>ans;
        int n=a.size(),i1=0,i2=0,m=b.size();
        while((i1<n)&& (i2<m)){
            if(a[i1]<b[i2]){
                ans.push_back(a[i1++]);
            }
            else if(a[i1]>b[i2]){
                ans.push_back(b[i2++]);
            }
            else{
                ans.push_back(b[i2]);
                i1++;i2++;
            }
        }
        while(i1<n){
            ans.push_back(a[i1++]);
        }
          while(i2<m){
            ans.push_back(b[i2++]);
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
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends