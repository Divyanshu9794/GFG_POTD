class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int hash[n+1]={0};
        int missing =-1 , repeating =-1;
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(hash[i]==2){
                repeating = i;
            }
            else if(hash[i]==0){
                missing =i;
            }
            if(missing != -1 && repeating != -1){
                break;
            }
        }
        return {repeating,missing};
    }
};