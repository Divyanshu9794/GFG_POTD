class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& nums1) {
        // code here
        vector<int> ans;
        stack<int> st;
        int n = nums1.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums1[i]){
                st.pop();

            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(nums1[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};