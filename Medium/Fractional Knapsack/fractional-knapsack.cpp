//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(pair<int,int>a,pair<int,int>b){
    
    double f=((1.0)*a.first)/a.second;
    double s=((1.0)*b.first)/b.second;
    return f>s;
}
class Solution
{
    public:
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({arr[i].value,arr[i].weight});
        }
        sort(vec.begin(),vec.end(),comp);
        double ans=0;
        for(int i=0;i<n;i++){
           
            if(vec[i].second<=W){
                ans+=vec[i].first;
                
                W-=vec[i].second;
            }
            else{
                double frac=((1.0)*vec[i].first)/vec[i].second;
                ans+=frac*W;
                
                W=0;
            }
        }
        return ans;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends