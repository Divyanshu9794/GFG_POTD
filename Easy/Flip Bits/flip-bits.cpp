//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int count=0, count1=0,ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(a[i]==1){
                count1++;
                a[i]=-1;
            }else{
                a[i]=1;
            }
        }
      
        for(int i=0;i<n;i++){
            count=count+a[i];
            if(ans<count){
                ans=count;
            }
            if(count<0){
                count=0;
            }
        }
       
        if(ans< 0) return count1;

        return ans+count1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends