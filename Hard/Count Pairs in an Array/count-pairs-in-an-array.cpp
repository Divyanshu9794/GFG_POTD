//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int cnt = 0;
    
    void merge(int arr[], int l, int mid, int r){
        vector<int> temp;
        int left = l;
        int right = mid+1;
        while(left <= mid && right <= r){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                cnt += mid - left+1;
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = l; i<=r; i++){
            arr[i] = temp[i-l];
        }
    }
    
    void mergeSort(int arr[], int l, int r){
        if(l>=r) return;
        int mid = (l+r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
        
    }
    
    int countPairs(int arr[] , int n ) 
    {
        for(int i=0; i<n; i++){
            arr[i] = i*arr[i];
        }
        mergeSort(arr, 0, n-1);
        return cnt;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends