//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
int f(int W,int wt[],int value[],int n)
    {
        
        if(n==0 || W<=0)
        return 0;
        
        //ignore the last item
        if(wt[n-1]>W)
        return f(W,wt,value,n-1);
        
        //include the last item
        else 
         return max(value[n-1] + f(W - wt[n-1], wt, value, n-1), 
                   f(W, wt, value, n-1));
        
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        
        int n=wt.size();
        int weight[n];
        
        for(int i=0;i<n;i++)
        weight[i]=wt[i];
        
        int value[n];
        for(int i=0;i<n;i++)
        value[i]=val[i];
        
        return f(W,weight,value,n);
        
        
    }
};




//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends