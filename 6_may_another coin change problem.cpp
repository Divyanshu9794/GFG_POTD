//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<int>ans(target+1);
         for(int i=0;i<N;i++){
             if(coins[i]<=target)
             ans[coins[i]]=1;
         }
         
         for(int i=2;i<=K;i++){
                 for(int k=target;k>0;k--){
                     int temp=0;
                     for(int j=0;j<N;j++){
                       if((k-coins[j])>0&&ans[k-coins[j]]){
                           temp = 1;break;
                       }
                     }
                     ans[k]=temp;
                 }
         }
         return (bool)ans[target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends