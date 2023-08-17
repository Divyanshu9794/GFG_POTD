//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void help(vector<int>&nms,vector<int>&ans,int strt,int end ){
    if(strt>end)return;
    int mid=(strt+end)/2;
    ans.push_back(nms[mid]);
    
    help(nms,ans,strt,mid-1);
    help(nms,ans,mid+1,end);
}
vector<int> sortedArrayToBST(vector<int>& nums) {
        int strt=0,end=nums.size()-1;
        vector<int>ans;
        help(nums,ans,strt,end);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends