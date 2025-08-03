class Solution {
  public:
  
    bool canwe(vector<int> &stalls,int dist, int cow){
        int c=1, last = stalls[0];
        int n = stalls.size();
        for(int i=1;i<n;i++){
            if(stalls[i]-last>=dist){
                c++;
                last = stalls[i];
            }
            if(c>=cow){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low =1,high = stalls[n-1]-stalls[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canwe(stalls,mid,k)==true){
                
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};