class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        vector<int> temp(arr.begin(),arr.end());
        vector<pair<int, int>> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(make_pair(abs(x-arr[i]), i));
        }
        sort(ans.begin(), ans.end(), [x](pair<int, int> &a, pair<int, int> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            else{
                return a.first<b.first;
            }
        });
        for(int i=0; i<arr.size(); i++){
            arr[i]= temp[ans[i].second];
        }
    }
};