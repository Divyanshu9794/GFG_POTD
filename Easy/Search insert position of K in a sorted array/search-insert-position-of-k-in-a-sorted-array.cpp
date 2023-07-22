//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int ans=N;
        for(int i=0;i<N;i++){
            int left=0;
            int right=N-1;
            while(left<=right){
                int mid = left + (right - left)/2;
                if(Arr[mid]>=k){
                   ans=mid;
                   right=mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends