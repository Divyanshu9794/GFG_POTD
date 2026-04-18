class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
         int curr =0,one =0, ans = 0;
        for(auto i: arr){
            if(curr <0)curr =0;
            if(i ==0)curr++;
            else {curr--;one++;}
            ans = max(ans , curr);
        }
        return ans + one;
        
    }
};