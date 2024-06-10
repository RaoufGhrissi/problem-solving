#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pp pair<char,int>

class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(), m.end());
        int ans = 0;

        int n = m.size();
        if (m[0][0] != 1)
            ans += m[0][0]-1;

        int end = m[0][1];

        for (int i=1 ; i<n ; i++) {
            int s = m[i][0];

            if (s > end) // fama gap
                ans += s-end-1;

            end = max(end, m[i][1]);
        }

        if (days > end)
            ans += days - end;

        return ans;
    }
};