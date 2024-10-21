#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string t) {
        vector<string> ans;
        string s = "";

        for (char &c:t) {
            s += "a";
            ans.push_back(s);
            
            while(s[s.size()-1] != c) {
                s[s.size()-1]++;
                ans.push_back(s);
            }
        }

        return ans;   
    }
};