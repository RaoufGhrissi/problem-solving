#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        int n = v.size();
        ll ans = 0;
        int mi = -1, mx = -1, out = -1;

        for (int i=0 ; i<n ; i++) {
            if (v[i] > maxK  || v[i] < minK) {
                out = i;
                continue;
            }

            mi = v[i] == minK ? i : mi;
            mx = v[i] == maxK ? i : mx;
            
            if (mi == -1 || mx == -1)
                continue;
            
            if (out > min(mi, mx))
                continue;

            ans += min(mi, mx) - out;
        }
        
        return ans;
    }
};