
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll,ll>
#define inf 1e18
#define ll long long
class Solution {
public:
    ll countSubstrings(string s, char t) {
        int prev = 0;
        ll ans = 0;

        for (auto &c:s) {
            if (c != t) continue;
            ans += prev+1;
            prev++;
        }

        return ans;
    }
};