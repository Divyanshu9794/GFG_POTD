//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    int res=0;
    while(n){
        int r;
        r=n%10;
        if(r==0)
        res=res*10+5;
        else  res=res*10+r;
        n=n/10;
    }
    int k=0;
    while(res){
        int re=res%10;
        k=k*10+re;
        res/=10;
    }
    return k;
}