#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    bool lezemTsagher = 0, lezemTzid = 0;
    string f, ss;
    int id;
    ll dp[20][2][2];
    int nn;
    int lmt;

    ll rec(int i, int zedt, int saghart) {
        if (i==nn) {
            if (lezemTsagher && !saghart) return 0;
            if (lezemTzid && !zedt) return 0;
            return 1;
        }

        ll &ans = dp[i][zedt][saghart];
        if (ans != -1)
            return ans;

        ans = 0;
        int mx = f[i] - '0';
        int l = !saghart ? min(lmt, mx) : lmt;

        int li = 0;
        int mi = ss[i] - '0';

        if (i>=id && !zedt) {
            li = mi;
        }
        for (int x=li ; x<=l ; x++) {
            int k = x < mx;
            int z = x > mi;

            ans += rec(i+1, zedt | z, saghart | k);
        }

        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        f = to_string(finish);
        ss = to_string(start);

        int n = s.size();
        
        nn = f.size() - n; // toul eli bech yetzed

        if (stoll(f.substr(nn)) < stoll(s))
            lezemTsagher = 1;

        id = f.size() - ss.size(); // ne9es l sghir bech ywali fard toul maa lekbir
        int diff = id;
        
        string sup = "";
        while(diff--)
            sup += '0';

        ss = sup + ss;

        if (stoll(ss.substr(ss.size()-n)) > stoll(s))
            lezemTzid = 1;

        diff = nn;
        sup = "";
        while(diff--)
            sup += '0';

        s = sup + s;
        memset(dp, -1, sizeof dp);
        lmt = limit;
        return rec(0, 0, 0);
    }
};