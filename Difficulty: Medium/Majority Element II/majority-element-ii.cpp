class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        unordered_map<int, int> mp;
        for (int& it : arr){
            mp[it]++;
        }
        int n = arr.size();
        vector<int> ans;
        for (auto& it : mp){
            if (it.second > n/3) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};