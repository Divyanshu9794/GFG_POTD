//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string pattern){
        std::stack<int> stk;
    std::string result;

    int current_min = 1;

    for (char ch : pattern + 'I') {
        stk.push(current_min);

        if (ch == 'I') {
            while (!stk.empty()) {
                result += std::to_string(stk.top());
                stk.pop();
            }
            current_min++;
        } else {
            current_min++;
        }
    }

    return result;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends