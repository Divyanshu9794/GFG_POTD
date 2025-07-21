class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int l=0, r=n-1;
        while(l<r){
            int sum = arr[l]+arr[r];
            if(sum<target){
                l++;
            }
            else if(sum==target){
                return true;
            }
            else{
                r--;
            }
        }
        return false;
    }
};