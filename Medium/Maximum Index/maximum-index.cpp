//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int A[], int N) {
   int left[N];
   int right[N];
   left[0]=A[0];
   right[N-1]=A[N-1];
   for(int i=1;i<N;i++){
       left[i]=min(left[i-1],A[i]);
   }
   for(int i=N-2;i>=0;i--){
       right[i]=max(right[i+1],A[i]);
   }
   int maxi=INT_MIN;
   int i=0,j=0;
   
   while(i<N&&j<N){
       if(left[i]<=right[j]){
           maxi=max(maxi,j-i);
           j++;
       }
       else{
       i++;
       }
   }
   return maxi;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends