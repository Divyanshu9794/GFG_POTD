class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        int n = nums.size(),maxi = INT_MIN, suf=1,pre=1;
        for(int i=0;i<=n-1;i++){
            if(suf==0){
                suf=1;
            }
            if(pre==0){
                pre =1;
            }
            pre = pre * nums[i];
            suf = suf * nums[n-i-1];
            maxi = max({maxi,suf,pre});
        }
        return maxi;
    }
};