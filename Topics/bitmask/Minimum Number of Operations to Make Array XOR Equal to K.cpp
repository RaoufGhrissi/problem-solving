#include <bits/stdc++.h>

using namespace std;

#define ll long long


class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int ans = 0;
        for (int i=0 ; i<20 ; i++) {
            int mask = 1<<i;
            int val = mask&k;
            int cnt = 0;
            for (auto &x:v) {
                int msk = x&mask;
                if (msk) cnt++;
            }

            if (val) {
                if (!(cnt&1)) ans++;
            } else {
                if (cnt&1) ans++;
            }
        }

        return ans;
    }
};