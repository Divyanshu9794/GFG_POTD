class Solution {
  public:
    virtual bool minTimeChecking(int x, vector<int> &a, int k){
      int painter=1;
      int sum=0;
      
      for(int &v: a){
        sum+=v;
        if(sum>x){ 
          painter++;
          sum=v;
          if(painter>k) return false;
        }
      }
      
      return painter<=k;
    }
    
    virtual int minTime(vector<int>& arr, int k){
      int s=*max_element(arr.begin(), arr.end());
      int e=accumulate(arr.begin(), arr.end(), 0);
      
      int ans=INT_MAX;
      while(s<=e){
        int m=s+(e-s)/2;
        
        if(minTimeChecking(m, arr, k)) { ans=m; e=m-1; }
        else s=m+1;
      }
      
      return ans;
    }
};