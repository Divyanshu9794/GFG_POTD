//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
       int left = 0;
        int right = 0;
        int found = -1;
        long long sum = arr.at(0);
        while (left<n && right<n)
        {
            if(sum==s)
            {
                found = 1;
                break;
            }
            else if (sum < s)
            {
                if (right==n-1)
                {
                    break;
                }
                sum = sum + arr[++right];
            }
            
            else if (sum > s)
            {
                sum = sum - arr[left++];
                if(left>right)
                {
                    right = left;
                    sum = arr[left];
                }
            }
        }
        vector<int> result;
        if (found ==1)
        {
            result = {left+1, right+1};
        }
        else
        {
            result = {-1};
        }
        return result;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends