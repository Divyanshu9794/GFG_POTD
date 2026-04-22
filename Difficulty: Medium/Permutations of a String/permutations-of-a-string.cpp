class Solution {
  public:
    void recur(int ind, string &s, set<string> &st) {
        if (ind == s.size()) {
            st.insert(s);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            swap(s[ind], s[i]);
            recur(ind + 1, s, st);
            swap(s[ind], s[i]); // backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        set<string> st;  // keeps things sorted + unique
        recur(0, s, st);
        return vector<string>(st.begin(), st.end());
    }
};