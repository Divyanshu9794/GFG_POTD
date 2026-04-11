

class Solution {
  public:
    vector<int> leaders(vector<int>& nums) {
        // code here
        vector<int> ans ;
        int leader = INT_MIN;
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            if(nums[i]>=leader){
                ans.push_back(nums[i]);
            }
            leader = max(leader,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};