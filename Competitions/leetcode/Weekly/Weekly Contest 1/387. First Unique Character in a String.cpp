#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occ(26, 0);
        for (auto &c:s)
            occ[c-'a']++;

        for (int i=0 ; i<s.size() ; i++) {
            if (occ[s[i]-'a'] == 1)
                return i;
        }

        return -1;
    }
};