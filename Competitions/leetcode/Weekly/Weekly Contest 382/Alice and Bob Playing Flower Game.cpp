#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll ans = 0;
        for (int i=1 ; i<=n ; i++) {
            if (i&1) { // odd so the comp should be even
                ans += m/2;    
            } else { // even so the comp should be odoo
                ans += m%2 ? m/2 + 1 : m/2;
            }
        }
        
        
        return ans;
    }
};