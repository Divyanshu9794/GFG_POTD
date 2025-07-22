class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
    int sum = 0;  
    int n = arr.size();

    if (n < 2) return 0;

    for (int i = 0; i < n - 1; i++) {
 
        if (arr[i] < arr[i + 1]) {

            sum += arr[i + 1] - arr[i]; 
        }
    }

    return sum;
    }
};