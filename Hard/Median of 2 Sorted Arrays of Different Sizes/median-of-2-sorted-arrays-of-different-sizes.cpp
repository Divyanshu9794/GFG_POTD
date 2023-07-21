//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n=array1.size();
        int m=array2.size();
        int x=n+m;
        vector<int> vec(x);
        int i=0,j=0,k=0;
        while(k<x&&i<n&&j<m){
            if(array1[i]<=array2[j])
            vec[k++]=array1[i++];
            else
            vec[k++]=array2[j++];
        }
        while(k<x&&i<n) 
        vec[k++]=array1[i++];
        while(k<x&&j<m)
        vec[k++]=array2[j++];
        double l=0,h=x-1,avg,mid=l+(h-l)/2;
        if(x%2!=0)
        return vec[mid];
        else
        {
            avg=((double)vec[mid]+vec[mid+1])/2;
            return avg;
        }
        
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
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends