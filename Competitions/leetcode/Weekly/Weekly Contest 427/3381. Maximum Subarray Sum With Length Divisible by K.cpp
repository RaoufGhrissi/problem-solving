#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& v, int k) {
        map<int, long long> mi;
        mi[k-1] = 0;

        long long ans = -1e15;

        vector<long long> cum(v.begin(), v.end());

        int n = v.size();

        for (int i=1 ; i<n ; i++) {
            cum[i] += cum[i-1];
        }

        for (int i=0 ; i<n ; i++) {
            int rest = i%k;

            if (!mi.count(rest)) {
                mi[rest] = cum[i];
            } else {
                ans = max(ans, cum[i] - mi[rest]);
                mi[rest] = min(mi[rest], cum[i]);
            }
        }

        return ans;
    }
};