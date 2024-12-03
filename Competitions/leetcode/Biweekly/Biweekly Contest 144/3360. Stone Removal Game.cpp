#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int nxt = 10;
        bool alice = 1;
        
        while(n >= nxt) {
            n -= nxt;
            nxt--;
            alice = !alice;
        }

        return !alice;
    }
};