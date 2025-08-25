class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        if(n%2 == 0)
            pq.push(arr[n/2 - 1]);
        
        for(int i = n/2; i < n; i++)
        {
            pq.push(arr[i]);    
        }
        
        while(k)
        {
            int top = pq.top();
            pq.pop();
            pq.push(top+1);
            k--;
        }
        
        if(n%2 == 0)
        {
            int top = pq.top();
            pq.pop();
            return (top + pq.top())/2;
        }
        else
            return pq.top();
    }
};