//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool isSubsetSum(vector<int>arr, int sum){
      // code here 
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = 0;
        int curr = 0;
        while(i<n && j<n){
            if(curr<sum){
                curr+=arr[j];
            }
            while(curr>sum){
                curr-=arr[i];
                i++;
            }
            if(curr==sum){
                return 1;
            }
            j++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends