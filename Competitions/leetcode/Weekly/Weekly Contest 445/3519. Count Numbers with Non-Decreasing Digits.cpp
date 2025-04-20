#include <bits/stdc++.h>
#define ll long long
using namespace std;

class ConvertToBase {
    public:
        ConvertToBase() {};

        string get(string s, int base) {
            string res = "";
            while(!s.empty()) {
                int n = s.size();
                string ans = "";
                int r = 0;

                for (int i=0 ; i<n ; i++) {
                    int x = s[i] - '0';
                    if (r) {
                        x = r*10 + x;
                    }

                    if (x >= base) {
                        int q = x/base;
                        r = x%base;
                        ans += q+'0';
                    } else {
                        if (!ans.empty())
                            ans += '0';
                            
                        r = x;
                    }
                }

                res += r + '0';
                s = ans;
            }

            reverse(res.begin(), res.end());

            return res;
        }
};

class Solution {
public:
    int mod = 1e9 + 7;
    string decrease(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;

        while(i<n && s[i] == '0') {
            s[i] = '9';
            i++;
        }

        s[i]--;

        if (i == n-1 && s[i] == '0')
            s.pop_back();

        reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;
    }

    ll dp[1000][2][10];

    ll rec(int i, int decr, int prev, string &origin, int &b) {
        if (i == origin.size())
            return 1;

        ll &ans = dp[i][decr][prev];

        if (ans != -1)
            return ans;

        ans = 0;
        if (decr) {
            int mx = b-1;
            int mi = i == 0 ? 0 : prev;

            for (int x=mi ; x<=mx ; x++) {
                ans = (ans + rec(i+1, decr, x, origin, b)) % mod;
            }
        } else {
            int mxx = origin[i]-'0';
            int mx = min(b-1, mxx); 
            int mi = i == 0 ? 0 : prev;

            for (int x=mi ; x<=mx ; x++) {
                ans = (ans + rec(i+1, x < mxx, x, origin, b)) % mod;
            }
        }   

        return ans;
    }

    int countNumbers(string l, string r, int b) {
        ConvertToBase toBase = ConvertToBase();
        string high = toBase.get(r, b);

        memset(dp, -1, sizeof dp);

        ll ans = rec(0, 0, 0, high, b);
        
        if (l == "0") return ans;
        memset(dp, -1, sizeof dp);

        string lll = decrease(l);
        string low = toBase.get(lll, b);

        ll sub = rec(0, 0, 0, low, b);
        ll res = ans - sub;

        if (res < 0) res += mod;

        return res;
    }
};