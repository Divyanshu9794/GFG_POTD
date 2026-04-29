class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(auto it:arr){
            if(it==1) total++;
        }
        if(total==0) return -1;
        int i=0,j=0;
        int one=0,zero=0,ans=INT_MAX;
        while(j<n){
            if(arr[j]==0) zero++;
            else one++;
            while(i<j && zero>(total-one)){
                if(arr[i]==0) zero--;
                else one--;
                i++;
            }
            ans=min(ans,max(zero,total-one));
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};