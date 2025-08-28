// User function Template for C++

class Solution {
public:
    string reverseString(string& s) {
        int n = s.size();
        int st =0;
        int e = n-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
        return s;
    }
};