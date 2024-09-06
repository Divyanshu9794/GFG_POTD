//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        int n = arr.size();
        long long sum=INT_MIN;
       int i = 0;
       long long temp=0;
       while(i<n){
           temp+=arr[i];
           if(temp>sum){
               sum = temp;
           }
           if(temp<0) temp=0;
           
           i++;
       }
       return sum;
    }
};

// class Solution{
//     public:
//     // arr: input array
//     // n: size of array
//   long long maxSubarraySum(int arr[], int n){

//       long long sum=INT_MIN;
//       int i = 0;
//       long long temp=0;
//       while(i<n){
//           temp+=arr[i];
//           if(temp>sum){
//               sum = temp;
//           }
//           if(temp<0) temp=0;
           
//           i++;
//       }
//       return sum;
//     }
    
// };



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends