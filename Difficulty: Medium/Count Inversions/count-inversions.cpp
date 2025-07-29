class Solution {
  public:
  int cnt =0;
  int merge(vector<int> &arr,int low,int mid,int high){
      vector<int> temp;
      int left = low, right = mid+1;
      while(left<=mid && right<=high){
          if(arr[left]<= arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          else{
              temp.push_back(arr[right]);
              cnt += (mid-left+1);
              right++;
          }
      }
      while(left<=mid){
          temp.push_back(arr[left]);
          left++;
      }
      while(right<=high){
          temp.push_back(arr[right]);
          right++;
      }
      for(int i=low;i<=high;i++){
          arr[i]=temp[i-low];
      }
      return cnt;
  }
  void mergesort(vector<int> &arr,int low,int high){
      if(low>=high){
          return;
      }
      int mid = (low+high)/2;
      mergesort(arr,low,mid);
      mergesort(arr,mid+1,high);
      merge(arr,low,mid,high);
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        mergesort(arr,0,n-1);
        return cnt;
        
    }
};