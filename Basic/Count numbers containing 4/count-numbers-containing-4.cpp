//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      int countNumberswith4(int N) {
        int cnt=0;
        for(int i=1;i<=N;i++){
            int t=i;
            while(t){
                if(t%10==4){
                    cnt++;
                    break;
                }
                t/=10;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends