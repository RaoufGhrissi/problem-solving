#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define ll long long

class Solution {
public:
    vector<vector<map<int, int>>> dp;

    int rec(int i, int j, int tot, vector<int> &v, vector<int> &vals, int &n, int &m) {
        if (i == n) return (j==m) ? 0 : inf;
        if (j == m) return inf;

        if (dp[i][j].count(tot))
            return dp[i][j][tot];

        int &ans = dp[i][j][tot]; 
        // pick or not
        // knapsak

        //if (tot == -1)
        //    tot = v[i];
        //else
        //    tot &= v[i];

        tot = v[i];
        ans = rec(i+1, j, tot, v, vals, n, m); // mat9osch, hez v[i] zidha ll and w kamel, j malezmch t9adem
        if (tot == vals[j]) // idha najem n9os (masmou7li)
            ans = min(ans, v[i] + rec(i+1, j+1, (1<<20)-1, v, vals, n, m));

        return ans;
    }

    int minimumValueSum(vector<int>& v, vector<int>& vals) {
        int n = v.size(), m = vals.size();
        dp.resize(n, vector<map<int,int>>(m));
        int res = rec(0, 0, (1<<20)-1, v, vals, n, m);
        return res < inf ? res : -1;
    }
};