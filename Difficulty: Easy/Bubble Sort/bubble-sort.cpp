class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<=i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
};