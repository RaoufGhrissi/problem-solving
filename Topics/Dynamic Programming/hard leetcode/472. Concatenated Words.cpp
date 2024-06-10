//https://leetcode.com/problems/concatenated-words/

#include <bits/stdc++.h>
#define inf (int)1e9;
using namespace std;

class Solution {
public:
    int dp[30];
    int ways(int i, string &s, set<string>& st) {
        if (i==s.size()) {
            return 1;
        }

        int &ans = dp[i];

        if (ans != -1)
            return ans;

        ans = 0;
        string ch = "";

        for (int j=i ; j<s.size() ; j++) {
            ch += s[j];

            if (st.count(ch)) {
                ans += ways(j+1, s, st);
            }
        }

        return ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& v) {
        set<string> st(v.begin(), v.end());
        vector<string> ans;

        for (auto &c:v) {
            memset(dp, -1, sizeof dp);
            if (ways(0, c, st) > 1)
                ans.push_back(c);
        }

        return ans;
    }
};