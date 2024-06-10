#include <bits/stdc++.h>

using namespace std;

#define inf 1e9

class Solution {
public:
    int minimumSubarrayLength(vector<int>& v, int k) {
        if (k==0) return 1;
        vector<int> cnt(30, 0);
        int ans = inf;
        int i = 0;
        int j = 0;
        int n = v.size();
        int _or = 0;

        while(j<n) {
            if (_or<k) {
                _or |= v[j];
                for (int x=0 ; x<30 ; x++) {
                    int mask = 1<<x;
                    if (mask&v[j])
                        cnt[x]++;
                }
                j++;
            } else {
                ans = min(ans, j-i);
                for (int x=0 ; x<30 ; x++) {
                    int mask = 1<<x;
                    if (mask&v[i]) {
                        cnt[x]--;
                        if (!cnt[x]) _or &= mask^((1<<30)-1);
                    }
                }
                i++;
            }
        }

        while(i<n && _or >= k) {
            ans = min(n-i, ans);
            for (int x=0 ; x<30 ; x++) {
                int mask = 1<<x;
                if (mask&v[i]) {
                    cnt[x]--;
                    if (!cnt[x]) _or &= mask^((1<<30)-1);
                }
            }
            i++;
        }

        return ans == inf ? -1 : ans;
    }
};

int main() {
    return 0;
}