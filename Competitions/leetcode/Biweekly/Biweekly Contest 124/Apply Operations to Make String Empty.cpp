#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char, int> occ;
        int mx = 0;
        for (auto &c:s) {
            occ[c]++;
            mx = max(mx, occ[c]);
        }
        
        int n = s.size();
        string ans = "";
        for (int i=n-1 ; i>-1 ; i--) {
            if (occ[s[i]] == mx) {
                ans += s[i];
                occ[s[i]]--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};