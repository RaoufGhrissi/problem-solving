#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<int> prev;
        int n = s.size();
        for (int i=0 ; i<n ; i++) {
            if (s[i]>='0' && s[i]<='9') {
                s[i] = '#';
                if (prev.empty()) continue;
                s[prev.top()] = '#';
                prev.pop();
            } else {
                prev.push(i);
            }
        }

        string ans = "";
        for (auto &a:s) {
            if (a!='#')
                ans += a;
        }

        return ans;
    }
};