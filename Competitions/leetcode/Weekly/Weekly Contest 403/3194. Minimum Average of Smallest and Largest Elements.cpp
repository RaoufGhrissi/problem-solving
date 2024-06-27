#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    double minimumAverage(vector<int>& v) {
        sort(v.begin(), v.end());
        double ans = 1e9, n = v.size();

        for (int i=0 ; i<n/2 ; i++) {
            ans = min(ans, (v[i]+v[n-1-i])/(double)2);
        }

        return ans;
    }
};