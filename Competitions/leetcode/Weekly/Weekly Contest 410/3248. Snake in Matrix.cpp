#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string, vector<int>> dir = {
        {"RIGHT", {0, 1}},
        {"LEFT", {0, -1}},
        {"DOWN", {1, 0}},
        {"UP", {-1, 0}},
    };
    int finalPositionOfSnake(int n, vector<string>& v) {
        int i=0, j=0;

        for (string &c:v) {
            i += dir[c][0];
            j += dir[c][1];
        }

        return i*n+j;
    }
};
