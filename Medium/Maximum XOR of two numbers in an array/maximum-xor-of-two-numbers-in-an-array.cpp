//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

struct Node {
    Node *links[2];
    
    bool containskey(int bit) {
        return (links[bit] != NULL);
    }
    Node *get(int bit) {
        return links[bit];
    }
    void put(int bit , Node *node) {
        links[bit] = node;
    }
};
class Trie {
    
    private :
    Node *root;
    
    public : 
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        
        Node*node = root;
        
        for(int i = 31 ; i >= 0 ;i--) {
            int bit = (num>>i) & 1;
            
            if(!node->containskey(bit)) {    //  If the bit is not present then add it to the trie 
                node->put(bit , new Node());
            }
           node = node->get(bit);  // else go to that bit 
        }
    }
    
    int getMax(int num) {
        
        Node *node = root;
        int maxnum = 0;
        
        for(int i = 31 ; i>= 0 ; i--) {
            
            int bit = (num >> i) &1;
            if(node->containskey(1-bit)) {          // if the trie contains opposite of bit 
            
 // ie . for 0 if there exist 1 , beacuse in that way we can maximise our number  
                maxnum = maxnum | (1 << i);
                node = node->get(1-bit);
            }
 
 // if opposite is not present then move to the same  bit
            else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        Trie trie;
        for(int i = 0 ; i< n ; i++) trie.insert(arr[i]);
        
        int maxi = 0 ;
        
        for(int i = 1 ; i < n ;i++) 
        {
            maxi = max(maxi , trie.getMax(arr[i]));
        }
        
        return maxi;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends