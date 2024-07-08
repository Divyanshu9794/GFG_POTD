//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int l=0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid] == key) return mid;
            if(arr[l] == key) return l;
            if(arr[r] == key) return r;
            if(arr[l] <= arr[mid]){
                if(arr[l]<=key && arr[mid] >= key){
                    r= mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(arr[mid] <=key && arr[r]>= key){
                    l=mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends