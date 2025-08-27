class Solution {
  public:
    int countTriangles(vector<int>& nums) {
        // code here
        int n = nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            int low=0;
            int high=i-1;
            while(low<high){
                if(nums[low]+nums[high]>nums[i]){
                    ans += (high-low);
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return ans;
        
    }
};
