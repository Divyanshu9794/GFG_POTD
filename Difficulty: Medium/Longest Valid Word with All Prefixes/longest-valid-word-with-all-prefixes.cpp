struct Node {
    Node* link[26];
    bool flag = false;

    bool containkey(char ch) {
        return link[ch - 'a'] != NULL;
    }
    Node* get(char ch) {
        return link[ch - 'a'];
    }
    void put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }
    void setend() {
        flag = true;
    }
    bool isend() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containkey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }

    bool checkifprefixexist(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containkey(word[i])) return false;
            node = node->get(word[i]);
            if (node->isend() == false) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        int n = words.size();
        Trie trie;
        for (auto &it : words) {
            trie.insert(it);
        }
        string longest = "";
        for (auto &it : words) {
            if (trie.checkifprefixexist(it)) {
                if (it.length() > longest.length()) {
                    longest = it;
                } else if (it.length() == longest.length() && it < longest) {
                    longest = it;
                }
            }
        }
        return longest;
    }
};
