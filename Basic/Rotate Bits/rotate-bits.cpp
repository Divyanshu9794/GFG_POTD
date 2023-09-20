//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
             vector<int> new_vec;

            d = d % 16;

            int left_ = (n<<d|(n>>(16-d)));

            int right_ = (n>>d|(n<<(16-d)));

            new_vec.push_back(left_&65535);

            new_vec.push_back(right_&65535);

            return new_vec;
        }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends