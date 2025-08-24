class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;
        vector<int> freq(n+1, 0);

        // Count frequency
        for(int x : arr){
            freq[x]++;
        }

        // Find missing and repeating
        for(int i=1; i<=n; i++){
            if(freq[i] == 0) missing = i;
            else if(freq[i] == 2) repeating = i;
        }

        return {repeating, missing};
    }
};
