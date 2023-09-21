//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
   
    vector<int> find(int arr[], int n , int x )
{
   int a = -1;

    int b = -1;

    int low = 0,high = n-1;

    while(low<=high){

        int mid = low + (high-low)/2;

        if(arr[mid]==x){

            a = mid;

            high = mid-1;

        }

        else if(arr[mid]>x){

            high = mid-1;

        }

        else{

            low = mid+1;

        }

    }

    low = 0,high = n-1;

    while(low<=high){

        int mid = low + (high-low)/2;

        if(arr[mid]==x){

            b = mid;

            low = mid+1;

        }

        else if(arr[mid]>x){

            high = mid-1;

        }

        else{

            low = mid+1;

        }

    }

    vector<int>c;

    c.push_back(a);

    c.push_back(b);

    return c;


}

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends