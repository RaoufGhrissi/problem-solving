#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int n = v.size();

        int mx = 0;
        for (int i=0 ; i<n ; i++) {
            if (v[i] > v[mx])
                mx = i;
        }

        int winner = 0;
        int wins = 0;
        for (int i=1 ; i<n ; i++) {
            if (v[winner] > v[i]) {
                wins++;
            } else {
                winner = i;
                wins = 1;
            }

            if (wins == k) {
                return winner;
            }
        }

        return mx;
    }
};