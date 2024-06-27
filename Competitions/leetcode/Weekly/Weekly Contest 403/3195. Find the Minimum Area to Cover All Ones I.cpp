#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int minimumArea(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int imi = 1e9, jmi = 1e9;
        int imx = -1, jmx = -1;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (v[i][j]) {
                    imi = min(i, imi);
                    jmi = min(j, jmi);
                    imx = max(i, imx);
                    jmx = max(j, jmx);
                }
            }
        }

        return imx == -1 ? 1e9 : (jmx - jmi + 1) * (imx - imi + 1);
    }
};