#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    ll largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());
        
        int n = v.size();
        ll ans = 0;
        ll total = v[0]+v[1];
        for (int i=2 ; i<n ; i++) {
            if (v[i] < total)
                ans = total + v[i];

            total += v[i];
        }

        return !ans ? -1 : ans;
    }
};