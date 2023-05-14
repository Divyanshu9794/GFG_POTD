class Solution {

  public:
      long long findMaxSubsetSum(int N, vector<int> &A) {
        
        long long pre, curr;
        pre=curr=0;
        for(int i=0; i<N; i++){
            curr=max(pre+A[i], curr+A[i]);
            swap(pre, curr);
        }
        return max(pre,curr);
    }
};
