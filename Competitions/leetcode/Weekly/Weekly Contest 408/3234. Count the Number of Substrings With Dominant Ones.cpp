#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> cum(n, 0);
        for (int i=0 ; i<n ; i++) {
            cum[i] = s[i]-'0';
            if (i)
                cum[i] += cum[i-1];
        }

        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            int j = i;
            int z, o;
            while(j<n) {
                o = cum[j];
                if (i)
                    o -= cum[i-1];

                z = j-i+1 - o;

                if (o >= z*z) {
                    ans++;
                    int diff = min(n-1-j, (int)sqrt(o) - z);
                    ans += diff;

                    j += diff+1;
                } else {
                    int diff = z*z - o;

                    j += diff;
                }
            }
        }

        return ans;
    }
};