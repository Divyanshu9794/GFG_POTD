class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int build=0, ptr=arr[0];
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=ptr){
                build++;
                ptr= arr[i];
            }
        }
        
        return build;
    }
};