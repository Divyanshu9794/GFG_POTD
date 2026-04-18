// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        long long t =0 , wttime=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++){
            wttime+=t;
            t+= bt[i];
        }
        return wttime/n;
    }
};