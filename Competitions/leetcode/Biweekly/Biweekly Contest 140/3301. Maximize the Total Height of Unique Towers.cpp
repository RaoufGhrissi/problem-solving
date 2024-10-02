#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        long long ans = 0;

        int mx = 1e9;

        for (int &x:v) {
            if (mx < 1) return -1;
            ans += min(x, mx);
            mx = min(x, mx)-1;
        }

        return ans;
    }
};