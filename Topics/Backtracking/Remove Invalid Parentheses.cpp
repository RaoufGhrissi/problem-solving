//https://leetcode.com/problems/remove-invalid-parentheses/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtrack(int i, string &s, string &ans, map<int, set<string>> &mp, int &occ) {
        if (i == s.size())
        {
            if (!occ) {
                mp[ans.size()].insert(ans);
            }

            return;
        }

        backtrack(i+1, s, ans, mp, occ);
        int toAdd = 0;
        if (s[i] == '(') toAdd++;
        else if (s[i] == ')') toAdd--;

        if (occ+toAdd >= 0) {
            ans.push_back(s[i]);
            occ += toAdd;
            backtrack(i+1, s, ans, mp, occ);
            occ -= toAdd;
            ans.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        map<int, set<string>> mp;
        string ans = "";
        int occ = 0;
        backtrack(0, s, ans, mp, occ);
        set<string> st = mp.rbegin()->second;
        return vector<string>(st.begin(), st.end());
    }
};
