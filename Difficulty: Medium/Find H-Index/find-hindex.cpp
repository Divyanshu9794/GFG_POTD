class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        vector<int>tmp(n+1, 0);
        
        for(int i=0; i<n; i++){
            tmp[min(n, citations[i])]++;
        }
        
        if(tmp[n]>=n) return n;
        for(int i=n-1; i>=0; i--){
            tmp[i]+=tmp[i+1];
            if(tmp[i]>=i) return i;
        }
        
        return 0;
    }
};