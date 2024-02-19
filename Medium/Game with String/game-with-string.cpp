//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        priority_queue<pair<int,int>> pq;
        map<int, int> mp;
        for(auto c : s) mp[c]++;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        while(k-- && !pq.empty()) {
            auto t = pq.top(); pq.pop();
            int freq = t.first, ch = t.second;
            freq--;
            pq.push({freq, ch});
        }
        int ans = 0;
        while(!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int freq = t.first, ch = t.second;
            ans += freq * freq;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends