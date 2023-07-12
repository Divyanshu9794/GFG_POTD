//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int> nextsmaller(vector<int> &arr, int n)
{
    stack<int>  s;
    s.push(-1);
    vector<int > ans(n);
    for(int i=n-1;i>=0;i--){
        int current = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=current){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> previoussmaller(vector<int> &arr, int n){
    stack<int>  s;
    s.push(-1);
    vector<int > ans(n);
    for(int i=0;i<n;i++){
        int current = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=current){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next=nextsmaller(heights,n);
        vector<int> previous;
        previous =previoussmaller(heights,n);
        int area= INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-previous[i]-1;
            int newarea= l*b;
            area=max(area,newarea);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxarea=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    h[j]++;
                    
                }
                else{
                    h[j]=0;
                }
            }
            int area= largestRectangleArea(h);
            maxarea=max(area,maxarea);
            
        }
        return maxarea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends