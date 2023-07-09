//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
class node{
    public:
        int data;
        int row;
        int col;
        node(int d,int r,int c)
        {
            data=d;
            row=r;
            col=c;
        }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
       
        int mini= INT_MAX,maxi=INT_MIN;

        priority_queue<node*,vector<node*>,compare> q;

        for(int i=0;i<k;i++){
            int ele = a[i][0];
            mini = min(mini,ele);
            maxi=max(maxi,ele);
            q.push(new node(ele,i,0));
        }

        int start=mini,end = maxi;
        while(!q.empty()){
            node* temp=q.top();
            q.pop();
            mini=temp->data;
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }


            if(temp->col+1<n){
                maxi=max(maxi,a[temp->row][temp->col+1]);
                q.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{

                break;
            }


        }
            return {start,end};
          
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends