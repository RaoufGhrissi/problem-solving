#include <bits/stdc++.h>

#define ll long long
using namespace std;


class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        int cum[n][26];
        memset(cum, 0, sizeof cum);

        for (int i=0 ; i<n ; i++) {
            cum[i][s[i]-'a']++;
        }

        for (int i=0 ; i<26 ; i++) {
            for (int j=1 ; j<n ; j++) {
                cum[j][i] += cum[j-1][i];
            }
        }

        vector<int> div;

        for (int i=1 ; i<=sqrt(n) ; i++)
        {
            if (n%i) continue;
            div.push_back(i);
            div.push_back(n/i);
        }

        for (int &sz:div) {
            bool ok = 1;
            int s = sz;

            while (s < n) {
                int end = s+sz-1;
                for (int i=0 ; i<26 ; i++) {
                    int cnt = cum[end][i] - cum[s-1][i];
                    int cnt1 = cum[sz-1][i];

                    if (cnt != cnt1) {
                        ok = 0;
                        break;
                    }
                }

                s += sz;

                if (!ok)
                    break;
            }

            if (ok) return sz;
        }

        return n;
    }
};