#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    string compressedString(string s) {
        string ans = "";
        
        int n = s.size();
        int cnt = 1;
        char c = s[0];
        for (int i=1 ; i<n ; i++) {
            if (s[i] == s[i-1]) {
                if (cnt < 9)
                    cnt++;
                else {
                    cnt = 1;
                    ans += '9';
                    ans += s[i];
                }
            } else {
                ans += cnt + '0';
                ans += c;
                cnt = 1;
                c = s[i];
            }
        }
        
        if (cnt > 0) {
            ans += cnt + '0';
            ans += c;
        }
        
        return ans;
    }
};