#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int occ[26];
    int dp[26][3][20001];

    int rec(int i, int rest, int &x) {
        if (i == 26)
            return 0;

        int &ans = dp[i][rest][x];

        if (ans != -1)
            return ans;
        
        int tot = occ[i];
        if (rest) { // tot < x for sure
            if (rest == 1)
                tot = min(x, tot + occ[i-1] - x);
            else
                tot = min(x, tot + occ[i-1]);
        }

        // transform to x
        if (tot <= x) { // missing numbers
            ans = min(x-tot + rec(i+1, 0, x), tot + rec(i+1, 0, x)); // add to reach x or delete to 0
            if (i+1 < 26 && occ[i+1] && occ[i+1] < x) { // delete a part and send the rest0 to the next
                ans = min(ans, tot + rec(i+1, 2, x));
            }
        } else { // delete the rest to reach x or transfer the rest to the next
            ans = tot-x + rec(i+1, 0, x);
            if (i+1 < 26 && occ[i+1] && occ[i+1] < x) {
                ans = min(ans, tot-x + rec(i+1, 1, x));
            }
        }

        return ans;
    }

    int makeStringGood(string s) {
        int n = s.size();

        memset(occ, 0, sizeof occ);
        memset(dp, -1, sizeof dp);

        for (char &c:s)
            occ[c-'a']++;

        int ans = 1e9;
        for (int i=0 ; i<=n ; i++) {
            int res = rec(0, 0, i);
            ans = min(ans, res);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution solution;

    cout << solution.makeStringGood("acab") << endl;

    return 0;
}