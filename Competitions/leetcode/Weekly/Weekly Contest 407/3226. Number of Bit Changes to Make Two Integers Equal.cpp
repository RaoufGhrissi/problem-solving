#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i=0 ; i<30 ; i++) {
            int mask = 1<<i;
            
            if (k&mask && !(n&mask))
                return -1;
            
            if (!(k&mask) && n&mask)
                ans++;
        }
        
        return ans;
    }
};