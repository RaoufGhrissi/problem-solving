#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int a = 1;
        int n = v.size();
        int ans = 1;

        for (int i=1 ; i<n ; i++) {
            if (v[i] > v[i-1]) {
                a++;
            } else {
                ans = max(ans, a);
                a = 1;
            }
        }

        ans = max(a, ans);
        a = 1;
        for (int i=1 ; i<n ; i++) {
            if (v[i] < v[i-1]) {
                a++;
            } else {
                ans = max(ans, a);
                a = 1;
            }
        }

        return max(a, ans);
    }
};