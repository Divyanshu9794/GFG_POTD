
class Solution {
public:
    vector<int> removeDuplicates(vector<int>& arr) {
        vector<int> ans;
        unordered_set<int> s;
        
        for(int x: arr){
            if(s.find(x) == s.end()){
                ans.push_back(x);
                s.insert(x);
            }
        }
        
        return ans;

        
    }
};