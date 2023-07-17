//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        list<int> ls;
        int i=0,j=0;
        vector<int> ans;
        while(j<n)
        {
           if(ls.empty())
           {
               ls.push_back(arr[j]);
           }
           else
           {
               while(ls.size()>0&&ls.back()<arr[j])
                ls.pop_back();
                ls.push_back(arr[j]);
               
           }
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k)
            {
                ans.push_back(ls.front());
                if(ls.front()==arr[i])
                    ls.pop_front();
                i++;j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends