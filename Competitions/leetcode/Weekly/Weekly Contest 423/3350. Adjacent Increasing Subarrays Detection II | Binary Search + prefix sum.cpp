#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& v) {
        int n = v.size();

        vector<int> cum(n-1, 0);

        for (int i=0 ; i<n-1 ; i++) {
            cum[i] = v[i+1] > v[i] ? 1 : 0;
            if (i) cum[i] += cum[i-1];
        }

        int i=1;
        int j=n;

        while(i<j) {
            int mid = (i+j+1)/2;

            bool ok = 0;
            for (int x=mid-1 ; x<n-mid ; x++) {
                int l = cum[x-1];
                int inc = mid-1;
                if (x-1-inc > -1) l-=cum[x-1-inc];

                if (l < inc) continue;

                int r = cum[x+inc] - cum[x];

                if (r < inc) continue;

                ok = 1;
            }

            if (ok)
                i = mid;
            else
                j = mid-1;
        }

        return i;
    }
};