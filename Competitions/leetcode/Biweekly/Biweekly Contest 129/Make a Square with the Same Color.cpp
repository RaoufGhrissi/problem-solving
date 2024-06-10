#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& v) {
        int w = 0;
        w = (v[0][0] == 'W') + (v[0][1] == 'W') + (v[1][0] == 'W') + (v[1][1] == 'W');
        
        if (w != 2) return 1;
        
        w = (v[0][1] == 'W') + (v[0][2] == 'W') + (v[1][1] == 'W') + (v[1][2] == 'W');
        
        if (w != 2) return 1;
        
        w = (v[1][0] == 'W') + (v[1][1] == 'W') + (v[2][0] == 'W') + (v[2][1] == 'W');
        
        if (w != 2) return 1;
        
        w = (v[1][1] == 'W') + (v[1][2] == 'W') + (v[2][1] == 'W') + (v[2][2] == 'W');
        
        if (w != 2) return 1;
        
        return 0;
    }
};