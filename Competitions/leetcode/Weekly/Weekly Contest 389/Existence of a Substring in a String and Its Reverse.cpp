
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        set<string> st;

        for (int i=1 ; i<n ; i++) {
            if (s[i] == s[i-1]) return 1;
            string t = "";
            t += s[i];
            t += s[i-1];

            if (st.count(t)) return 1;
            t = "";
            t += s[i-1];
            t += s[i];
            st.insert(t);
        }

        return 0;
    }
};