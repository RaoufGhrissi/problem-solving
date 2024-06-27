#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int n = c.size();
        for (int i=0 ; i<n ; i++) {
            if (g[i]) {
                g[i] = c[i];
                c[i] = 0;
            }

            if (i) {
                g[i] += g[i-1];
                c[i] += c[i-1];
            }
        }

        int ans = 0;
        for (int i=m-1 ; i<n ; i++)
            ans = max(ans, c[n-1] + g[i] - (i-m > -1 ? g[i-m] : 0));

        return ans;
    }
};