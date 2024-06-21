//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isDigit(char a){
        if(a >= '0' && a <= '9') return true;
        return false;
    }
    string compareFrac(string str) {
        string arr[5];
        int k = 0;
        for(auto it: str){
            if(isDigit(it)){
                arr[k] += it;
            }
            else{
                k++;
            }
        }
        int a = stoi(arr[0]);
        int b = stoi(arr[1]);
        int c = stoi(arr[3]);
        int d = stoi(arr[4]);
        
        if((double)a/b >(double)c/d){
            return arr[0]+'/'+arr[1];
        }
        else if((double)a/b <(double)c/d){
            return arr[3]+'/'+arr[4];
        }
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends