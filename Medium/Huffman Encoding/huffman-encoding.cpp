//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    
	public:
	struct Node{
	    long long freq;
	    
	    Node *left=NULL,*right=NULL;
	    Node(int f){
	        this->freq=f;
	        
	    }
	};
	struct Compare{
	    bool operator()(Node *l,Node *r){
	        return (l->freq > r->freq);
	    }
	};
	
	vector<string> res;
	void printcode(Node* root,string x){
	    if(!root->left && !root->right){
	        res.push_back(x);
	        return ;
	    }
	    printcode(root->left,x+"0");
	    printcode(root->right,x+"1");
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,Compare> pq;
		    for(int i=0;i<N;i++){
		        pq.push(new Node(f[i]));
		        
		    }
		    while(pq.size()>1){
		        Node* l= pq.top();
		        pq.pop();
		        Node* r= pq.top();
		        pq.pop();
		        Node* node = new Node(l->freq+r->freq);
		        node->left=l;
		        node->right=r;
		        pq.push(node);
		        
		    }
		    Node* root= pq.top();
		    printcode(root,"");
		    return res ;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends