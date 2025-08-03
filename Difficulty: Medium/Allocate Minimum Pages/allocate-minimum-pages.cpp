class Solution {
  public:
  
    int count(vector<int>& arr,int page){
        int n = arr.size();
        int student =1;
        long long stupage = 0;
        for(int i=0;i<n;i++){
            if(stupage + arr[i]<=page){
                stupage += arr[i];
            }
            else{
                student ++;
                stupage = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n){
            return -1;
        }
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low + high)/2;
            int student = count(arr,mid);
            if(student>k){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
    }
};