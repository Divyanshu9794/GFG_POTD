class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                ans.push_back(asteroids[i]);
            }
            else {
                while(!ans.empty() && ans.back()>0 && ans.back()<abs(asteroids[i])){
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back()== abs(asteroids[i])){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back()<0){
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
};
