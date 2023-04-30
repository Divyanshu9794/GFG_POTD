#include <iostream>
#include <vector>
using namespace std;

int determineWinner(vector<int>& player1, vector<int>& player2) {
    int n = player1.size();
    int score1 = 0, score2 = 0;
    bool strike1[3] = {false}, strike2[3] = {false};
    for (int i = 0; i < n; i++) {
        if (player1[i] == 10) {
            score1 += 2 * player1[i] + player1[i+1] + player1[i+2];
            if (i >= 1 && strike1[0]) {
                score1 += player1[i+1];
            }
            if (i == 0 || (i >= 2 && strike1[1])) {
                score1 += player1[i+1];
            }
            strike1[2] = strike1[1];
            strike1[1] = strike1[0];
            strike1[0] = true;
        } else if (i >= 1 && player1[i] + player1[i-1] == 10) {
            score1 += 2 * player1[i] + player1[i+1];
            if (i >= 2 && strike1[1]) {
                score1 += player1[i+1];
            }
            strike1[2] = strike1[1];
            strike1[1] = true;
            strike1[0] = false;
        } else {
            score1 += player1[i];
            strike1[2] = false;
            strike1[1] = false;
            strike1[0] = false;
        }
        if (player2[i] == 10) {
            score2 += 2 * player2[i] + player2[i+1] + player2[i+2];
            if (i >= 1 && strike2[0]) {
                score2 += player2[i+1];
            }
            if (i == 0 || (i >= 2 && strike2[1])) {
                score2 += player2[i+1];
            }
            strike2[2] = strike2[1];
            strike2[1] = strike2[0];
            strike2[0] = true;
        } else if (i >= 1 && player2[i] + player2[i-1] == 10) {
            score2 += 2 * player2[i] + player2[i+1];
            if (i >= 2 && strike2[1]) {
                score2 += player2[i+1];
            }
            strike2[2] = strike2[1];
            strike2[1] = true;
            strike2[0] = false;
        } else {
            score2 += player2[i];
            strike2[2] = false;
            strike2[1] = false;
            strike2[0] = false;
        }
    }
    if (score1 > score2) {
        return 1;
    } else if (score2 > score1) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    vector<int> player1 = {2, 8, 2, 10, 6};
    vector<int> player2 = {10, 7, 4, 5, 9};
    cout << determineWinner(player1, player2) << endl;  // Output: 2
    return 0;
}
