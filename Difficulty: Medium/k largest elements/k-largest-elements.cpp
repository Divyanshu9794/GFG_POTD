class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        int n = arr.size();
        vector<int> ans;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        
    }
};
