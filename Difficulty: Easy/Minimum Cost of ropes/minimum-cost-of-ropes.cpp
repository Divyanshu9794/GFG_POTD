//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    long long minCost(vector<long long>& arr) {
        int n = arr.size();
          priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long cost=0;
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long sum=a+b;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};



//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends