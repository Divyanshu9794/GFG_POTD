class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        if (N % groupSize != 0) {
            return false;
        }
        
        map<int, int> cardCount;
        for (int num : hand) {
            cardCount[num]++;
        }
        
        while (!cardCount.empty()) {
            int start = cardCount.begin()->first;
            for (int i = start; i < start + groupSize; i++) {
                if (cardCount.find(i) == cardCount.end()) {
                    return false;
                }
                cardCount[i]--;
                if (cardCount[i] == 0) {
                    cardCount.erase(i);
                }
            }
        }
        
        return true;
    }
};
