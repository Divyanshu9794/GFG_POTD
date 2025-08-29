class Solution {
public:
    string smallestWindow(string &s, string &p) {
        vector<int> required(26, 0);
        int uniqueNeeded = 0;
        for (char ch : p) {
            if (required[ch - 'a'] == 0) {
                uniqueNeeded++;
            }
            required[ch - 'a']++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        int needed = uniqueNeeded;
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            required[ch - 'a']--;

            if (required[ch - 'a'] == 0) {
                needed--;
            }
            while (needed == 0) {
                int windowLen = right - left + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = left;
                }

                required[s[left] - 'a']++;
                if (required[s[left] - 'a'] > 0) {
                    needed++;
                }
                left++;
            }
        }

        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLen);
    }
};
