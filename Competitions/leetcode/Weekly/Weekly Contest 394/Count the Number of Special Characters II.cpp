#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define ll long long

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int ans = 0;
        for (char c='a' ; c<='z' ; c++) {
            bool up = 0, lo = 0;
            for (char &ch:s) {
                if (tolower(ch) != c) continue;
                if (isupper(ch)) {
                    if (!lo) break;
                    up = 1;
                } else {
                    if (up) {
                        up = 0;
                        lo = 0;
                        break;
                    }
                    lo = 1;
                }
            }

            ans += up && lo;
        }

        return ans;
    }
};