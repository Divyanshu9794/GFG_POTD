
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        map<long long,int>presum;
        long long sum =0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            if(sum==k){
                maxlen = max(maxlen,i+1);
                
            }          
            long long rem = sum - k ;
            if(presum.find(rem)!=presum.end()){
                int len = i-presum[rem];
                maxlen = max(maxlen,len);
            }
            if(presum.find(sum)== presum.end()){
                presum[sum]=i;
            }
        }
        return maxlen;
    }
};