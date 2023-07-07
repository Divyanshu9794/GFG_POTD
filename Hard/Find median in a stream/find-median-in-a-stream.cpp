//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to insert heap.
priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    void insertHeap(int &x)
    {
         if(maxheap.empty() and minheap.empty()){
             maxheap.push(x);
         }
         else {
             if(maxheap.size()>minheap.size()){
                 if(maxheap.top()>x){
                     minheap.push(maxheap.top());
                     maxheap.pop();
                     maxheap.push(x);
                 }
                 else {
                     minheap.push(x);
                 }
             }
             else 
             if(x<=maxheap.top()){
                 maxheap.push(x);
             }
             else {
                 minheap.push(x);
                 maxheap.push(minheap.top());
                 minheap.pop();
             }
         }
    }
    //Function to return Median.
    double getMedian()
    {
        if(maxheap.size()==minheap.size()) {
            return ((maxheap.top()+minheap.top())/2.0);
        }
        return maxheap.top();
    }


};




//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends