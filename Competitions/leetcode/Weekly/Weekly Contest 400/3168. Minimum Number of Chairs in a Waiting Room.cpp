#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pp pair<char,int>

class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int mx = 0;

        for (auto &c:s) {
            if (c == 'E') ans++;
            if (c == 'L') ans--;

            mx = max(ans, mx);
        }

        return mx;
    }
};