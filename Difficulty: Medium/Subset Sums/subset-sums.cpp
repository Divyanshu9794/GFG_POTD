class Solution {
  public:
  void fun(int ind,int sum, vector<int> &arr,int N,vector<int>& sumsubset){
      if(ind == N){
          sumsubset.push_back(sum);
          return ;
      }
      fun(ind+1, sum + arr[ind], arr,N,sumsubset);
      fun(ind+1,sum,arr,N,sumsubset);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int N = arr.size();
        vector<int> sumsubset;
        fun(0,0,arr,N,sumsubset);
        sort(sumsubset.begin(),sumsubset.end());
        return sumsubset;
        
    }
};