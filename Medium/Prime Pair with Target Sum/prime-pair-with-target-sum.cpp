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
    vector<int> getPrimes(int n) {
        bool is_prime[n+1];
        memset(is_prime,true,sizeof(is_prime));
        is_prime[0]=is_prime[1]=false;
        for(int p=2;p*p<=n;p++){
            if(is_prime[p]){
                for(int i=p*p;i<=n;i +=p){
                    is_prime[i] = false;
                }
            }
        }
        for(int i=n;i>=n/2;i--){
            if(is_prime[i] and is_prime[n-i]) return {n-i,i};
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends