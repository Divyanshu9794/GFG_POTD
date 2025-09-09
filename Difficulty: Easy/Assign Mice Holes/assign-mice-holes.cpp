class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        vector<int>v;
        for(int i=0;i<holes.size();i++){
            int a=mices[i]-holes[i];
            int b=holes[i]-mices[i];
            if(a>0){
                v.push_back(a);
            }
            else v.push_back(b);
            
        }
        return *max_element(v.begin(),v.end());
    }
};