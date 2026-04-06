class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int rowindex) {
        // code here
        vector<int> ansrow;
        long long ans =1;
        ansrow.push_back(ans);
        for(int i=1;i<rowindex;i++){
            ans = ans * (rowindex-i);
            ans = ans / (i);
            ansrow.push_back(ans);
        }
        return ansrow;
    }
};
