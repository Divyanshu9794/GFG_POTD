class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() &&st.top()>= arr[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        return pse;
    }
};