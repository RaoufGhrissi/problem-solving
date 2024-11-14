#include<bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int> endd(n, -1);

        ll ans = 0;
        int j = n-1;
        for (int i=0 ; i<n ; i++) {
            int r = upper - v[i];

            while(j>-1 && v[j] > r)
                j--;

            endd[i] = j;
        }

        j = n;
        for (int i=0 ; i<n ; i++) {
            int r = lower - v[i];

            while(j>0 && v[j-1] >= r)
                j--;

            if (j==n || j > endd[i]) continue;

            ll tot = endd[i]-j+1;
            if (v[i] >= v[j] && v[i] <= v[endd[i]]) tot--;

            ans += tot;
        }

        return ans/2;
    }
};
