#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int n, m;
    unordered_set<int> st;
    int dp[3001][3001];

    int rec(int i, int j, string &s, string &p) {
        if (j == m) { // khlat kawantou l p
            return 0; // min
        }

        if (i == n) { // source wfet wel p mawftch
            return 1e4; // nraja3 noumrou kbir bech nehlek = abondoni tri9 adheka
        }

        int &ans = dp[i][j];

        if (ans != -1)
            return ans; // 7sebneh 9bal

        ans = rec(i+1, j, s, p); // zapih nagez mathezouch
        
        if (s[i] == p[j]) {
            int cnt = st.count(i) ? 1 : 0; // 1 => rani sta3mlt wehed mel ids => mahich hadaf mte3i 
            ans = min(ans, cnt + rec(i+1, j+1, s, p));
        }

        return ans;
    }

    int maxRemovals(string s, string p, vector<int>& ids) {
        for (int &i:ids)
            st.insert(i);

        n = s.size();
        m = p.size();

        memset(dp, -1, sizeof dp);

        return ids.size() - rec(0, 0, s, p); 
    }
};