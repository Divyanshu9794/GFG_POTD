//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
     static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }else{
            return a.first<b.first;
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)>trev(cmp);
        
        for(auto i:mp){
            trev.push({i.second,i.first});
        }
        
        while(!trev.empty()){
            int n=trev.top().second;
            int f=trev.top().first;
            trev.pop();
            for(int i=0;i<f;i++){
                ans.push_back(n);
            }
        }
        
        return ans;
        
    }


};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends