//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
  sort(arr,arr+size);
    int left=0,right=1;
    while(left<=right && right<=size-1){
        int diff=arr[right]-arr[left];
        if(diff==n && left!=right)
        return true;
        else if(diff>n)
        left++;
        else
        right++;
    }
    return false;
    
}