class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (k > n) return 0;
        int xorSum = 0;
        for (int i = 0; i < k; ++i) xorSum ^= arr[i];
        int maxXor = xorSum;
        for (int i = k; i < n; ++i) {
            xorSum ^= arr[i] ^ arr[i - k];
            maxXor = max(maxXor, xorSum);
        }
        return maxXor;
    }
};