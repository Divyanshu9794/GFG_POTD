//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        vector<int> ans(m);
        sort(arr2,arr2+n);
        for(int i=0;i<m;i++){
            int ind=-1;
            int left=0;
            int right=n-1;
            while(left<=right){
                int mid = left + (right - left)/2;
                if(arr2[mid] <= arr1[i]){
                    ind=mid;
                    left=mid+1;
                    
                }
                else{
                    right=mid-1;
                }
                
            }
            if(ind==-1){
                ans[i] = 0;
                
            }
            else{
                ans[i] = ind+1;
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
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends