#include <bits/stdc++.h>

#define ll long long
using namespace std;


class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        map<string, int> cnt;
        int n = s.size();

        int i = 0;
        int mx = 0;
        while(i<n) {
            string sub = s.substr(i, k);
            cnt[sub]++;
            mx = max(mx, cnt[sub]);
            i += k;
        }

        return n/k - mx;
    }
};