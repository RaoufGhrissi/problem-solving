#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        ll ans = 0;
        ll pos = 0;
        for (int i=0 ; i<60 ; i++) {
            ll mask = 1ll<<i;
            if (mask&x)
                ans |= mask;
            else {
                ll msk = 1ll<<pos;
                if (msk&n)
                    ans |= mask;
                pos++;
            }
        }
        return ans;
    }
};