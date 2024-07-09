#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    vector<string> ans;
    void backtrack(string &s, int &n) {
        int l = s.size();
        if (l == n) {
            ans.push_back(s);
            return;
        }
        
        if (!l || s[l-1] == '1') {
            s += '0';
            backtrack(s, n);
            s.pop_back();
        }
        
        s += '1';
        backtrack(s, n);
        s.pop_back();
    }
    
    vector<string> validStrings(int n) {
        string s = "";
        backtrack(s, n);
        return ans;
    }
};