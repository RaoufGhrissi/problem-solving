#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> occ(26, 0);
        int ans = 0;
        int done = 0;
        int n = s.size();
        int j = 0;

        for (int i=0 ; i<n ; i++) {
            while(j<n && !done) {
                occ[s[j]-'a']++;
                done += occ[s[j]-'a'] == k;
                j++;
            }

            if (done)
                ans += n-j+1;

            done -= occ[s[i]-'a'] == k;
            occ[s[i]-'a']--;
        }

        return ans;
    }
};