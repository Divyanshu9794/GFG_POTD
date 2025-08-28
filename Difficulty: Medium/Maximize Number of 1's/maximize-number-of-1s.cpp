class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int ans=0;
        int l=0;
        int h=0;
        int zero=0;
        while(h<arr.size()){
            if(arr[h]==0){
                zero++;
            }
            while(l<=h and zero>k){
                if(arr[l]==0){
                    zero--;
                }
                l++;
            }
            ans=max(ans,h-l+1);
            h++;
        }
        return ans;
    }
};
