//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        std::vector<bool> matched(A.size(),false);
        
        for(auto& phrase: B) // O(12)
        {
            std::size_t beg{0};
            
            while((beg = A.find(phrase, beg)) != std::string::npos) // O(N^2)
            {
                for(int i{beg}; i < beg + phrase.size(); i++)
                {
                    matched[i] = true;
                }
                beg++;
            }
        }
        
        return std::accumulate(matched.begin(), matched.end(), 0) == matched.size();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends