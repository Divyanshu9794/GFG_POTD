class Solution {
  public:
    bool solve(int maxtime,vector<int>&ranks,int n){
        int count=0;
        for(int i=0;i<ranks.size();i++){
             int sum=0;
             int k=1;
             while(sum+ranks[i]*k<=maxtime){
                 sum+=ranks[i]*k;
                 k++;
                 count++;
                if(count>=n) return true;
             }
        }
        return false;
    }
    int minTime(vector<int>& ranks, int n) {
        // code here
        sort(ranks.begin(),ranks.end());
        int m=ranks.size();
        int l=0,r=ranks[0]*(n*(n+1)/2);
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(mid,ranks,n)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};