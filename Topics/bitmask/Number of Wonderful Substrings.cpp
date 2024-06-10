#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll wonderfulSubstrings(string s) {
        int mask = 0;
        map<int,ll> prev;
        prev[0] = 1;

        ll ans = 0;
        for (char &c:s) {
            int bit = c-'a';
            mask ^= (1<<bit);

            ans += prev.count(mask) ? prev[mask] : 0;

            for (int i=0 ; i<10 ; i++) {
                int comp = (1<<i)^mask;
                ans += prev.count(comp) ? prev[comp] : 0;
            }

            prev[mask]++;
        }

        return ans;
    }
};

int main() {
    cout<<Solution().wonderfulSubstrings("aba");
    return 0;
}