//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    vector<int> vect ; 
    vector<int> ans ;
    for(int i = 0 ; i < n ; i++)
    {
        ans.push_back(arr[i]) ;
    }
    sort(ans.begin() , ans.end()) ;
    for(int i = 0 ; i < n ; i++)
    {
        int si = 0 ; 
        int ei = ans.size()-1 ;
        while(si<=ei)
        {
            int mid = (si+ei)/2 ;
            if(ans[mid] == arr[i])
            {
                if(si != ei)
                {
                    ei = mid ;
                    continue ;
                }
                vect.push_back(mid) ;
                ans.erase(ans.begin()+mid) ;
                break ;
            }
            else if(ans[mid]>arr[i])
            {
                ei = mid-1 ;
            }
            else
            {
                si = mid+1 ;
            }
        }
        
    }
    return vect ;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends