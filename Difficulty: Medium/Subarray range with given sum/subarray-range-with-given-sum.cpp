//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int sum)
    {
        int n = arr.size();
        unordered_map<int,int> s;
        int count =0;
        int temp_sum=0;
        for(int i=0;i<n;i++)
        {
            temp_sum += arr[i];
            int find = temp_sum-sum;
            if(temp_sum==sum)
            {
                count++;
            }
            if(s[find]>0)
            {
                count += s[find];
            }
             s[temp_sum]++;
        }
        return count;
      
    
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends