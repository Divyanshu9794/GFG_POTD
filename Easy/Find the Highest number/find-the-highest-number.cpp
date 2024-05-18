//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return arr[mid];
            else
            {
                high = mid - 1;
                ans = high;
            }
        }
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return arr[mid];
            else
            {
                low = mid + 1;
                ans = low;
            }
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else
        {
            if (arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
                ans = low;
            }
            else
            {
                high = mid - 1;
                ans = high;
            }
        }
    }
    return arr[ans];
}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends