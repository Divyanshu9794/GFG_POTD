class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<=n-2;i++){
            int mini = i;
            for(int j=i;j<=n-1;j++){
                if(arr[j]<arr[mini]){
                    mini = j;
                }
            }
                swap(arr[mini],arr[i]);
        }
        
    }
};