class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int miss =1;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<miss){
                continue;
            }
            else if(arr[i]==miss){
                miss++;
            }
            else if(arr[i]>miss){
                return miss;
            }
        }
        return miss;
    }
};