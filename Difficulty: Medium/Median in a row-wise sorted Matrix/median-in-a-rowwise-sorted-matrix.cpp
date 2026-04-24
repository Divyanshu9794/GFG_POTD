class Solution {
  public:
    int upperbound(vector<int> &arr,int x,int n ){
        int low =0, high =n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
    int countsmall(vector<vector<int>> &mat,int n,int m,int x){
        int cnt =0;
        for(int i=0;i<n;i++){
            cnt+= upperbound(mat[i],x,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for(int i =0;i<n;i++){
            low = min(low,mat[i][0]);
            high = max(high , mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low<=high){
            int mid = (low+high)/2;
            int smalleq = countsmall(mat,n,m,mid);
            if(smalleq <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
