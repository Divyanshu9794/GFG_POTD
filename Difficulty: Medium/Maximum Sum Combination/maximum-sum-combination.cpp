class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int,int>> vis;
        vector<int> ans;

        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});

        while(k-- && !pq.empty()){
            auto it = pq.top();
            pq.pop();

            int sum = it.first;
            int i = it.second.first;
            int j = it.second.second;

            ans.push_back(sum);

            if(i + 1 < n && vis.find({i+1, j}) == vis.end()){
                pq.push({a[i+1] + b[j], {i+1, j}});
                vis.insert({i+1, j});
            }

            if(j + 1 < n && vis.find({i, j+1}) == vis.end()){
                pq.push({a[i] + b[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }

        return ans;
    }
};