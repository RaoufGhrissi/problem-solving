#include <bits/stdc++.h>
//https://leetcode.com/problems/maximum-score-words-formed-by-letters/
using namespace std;



class Solution {
public:
    int maxScoreWords(vector<string>& v, vector<char>& l, vector<int>& s) {
        int n = v.size();
        vector<int> occ(26, 0);

        for (auto &c:l)
            occ[c-'a']++;

        vector<int> temp;
        int ans = 0;

        for (int i=0 ; i<(1<<n) ; i++) {
            temp = occ;
            int tot = 0;
            bool ok = 1;
            for (int j=0 ; j<n ; j++) {
                int mask = 1<<j;

                if (mask&i) {
                    for (auto &c:v[j]) {
                        if (!temp[c-'a']) {
                            ok = 0;
                            break;
                        }

                        tot += s[c-'a'];
                        temp[c-'a']--;
                    }
                }

                if (!ok)
                    break;
            }

            if (ok)
                ans = max(ans, tot);
        }

        return ans;
    }
};