#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans = "";
        for (char &c:s) {
            while (!ans.empty() && ans[ans.size()-1] > c && k) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || c != '0')
                ans += c; 
        }

        while(k-- && !ans.empty())
            ans.pop_back();

        return ans == "" ? "0" : ans;
    }
};