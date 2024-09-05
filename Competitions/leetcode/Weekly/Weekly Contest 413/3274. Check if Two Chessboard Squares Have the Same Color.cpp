#include <bits/stdc++.h>

using namespace std;


#define ll long long

class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int x1 = c1[0] - 'a';
        int x2 = c2[0] - 'a';
        
        int y1 = c1[1] - '0';
        int y2 = c2[1] - '0';
        
        // x&1 = 1 if x impair else = 0 idha x pair
        if ((x1&1 && x2&1) || (!(x1&1) && !(x2&1))) { // zouz impair wala zouz pair
            //zouz fard parité
            if (y1&1 && y2&1) return 1;
            if (!(y1&1) && !(y2&1)) return 1;
            
            return 0;
        }
        
        if (y1&1 && y2&1) return 0;
        if (!(y1&1) && !(y2&1)) return 0;
        
        return 1;
    }
};