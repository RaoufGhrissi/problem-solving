#include <bits/stdc++.h>

using namespace std;

#define ll long long


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& v) {
        vector<int> w;

        int i = 0;
        int n = v.size();

        int ans = 0;

        while(i<n) {
            int j = i+1;
            while(j<n && v[j]>v[j-1]) j++;

            w.push_back(j-i);
            i = j;
            j = i+1;
        }

        n = w.size();
        for (int i=0 ; i<n ; i++) {
            ans = max(ans, w[i]/2);

            if (i) ans = max(ans, min(w[i-1], w[i]));
            if (i+1<n) ans = max(ans, min(w[i+1], w[i]));
        }

        return ans;
    }
};