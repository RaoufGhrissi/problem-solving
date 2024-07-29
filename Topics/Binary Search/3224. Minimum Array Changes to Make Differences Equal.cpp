#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& v, int k) {
        vector<int> diff;
        vector<int> exact(k+1, 0);
        int n = v.size();

        for (int i=0 ; i<n/2 ; i++) {
            int mi = min(v[i], v[n-1-i]);
            int mx = max(v[i], v[n-1-i]);

            diff.push_back(max(k-mi, mx));
            exact[abs(v[i]-v[n-1-i])]++;
        }

        sort(diff.begin(), diff.end());

        int ans = 1e9;

        for (int x=0 ; x<=k ; x++) {
            int pos = lower_bound(diff.begin(), diff.end(), x) - diff.begin();
            ans = min(ans, 2*pos + (int)diff.size()-pos-exact[x]);
        }

        return ans;
    }
};