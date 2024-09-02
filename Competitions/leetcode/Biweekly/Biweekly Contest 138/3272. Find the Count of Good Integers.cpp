#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int dpCnk[11][11];
    int dp[6][100001];
    set<string> st;

    int cnk(int n, int k) {
        if (!n) {
            return !k ? 1 : 0;
        }

        if (!k)
            return 1;

        int &ans = dpCnk[n][k];

        if (ans != -1)
            return ans;

        return ans = cnk(n-1, k) + cnk(n-1, k-1);
    }
    
    ll rec(int i, int number, int &n, int &k) {
        if (
            ((n&1) && i == (n/2 + 1)) ||
            (!(n&1) && i == n/2)
        ) {
            string s = to_string(number);
            string comp = s;

            if (n&1)
                comp.pop_back();

            reverse(comp.begin(), comp.end());
            s += comp;

            ll x = stoll(s);
            sort(s.begin(), s.end());

            ll res = 1;
            if (x%k == 0) {
                    if (st.count(s)) return 0;
                st.insert(s);
                char prev = s[0];
                int cnt = 1;
                int nn = n;

                for (int id=1 ; id<s.size() ; id++) {
                    if (s[id] == prev)
                        cnt++;
                    else {
                        res *= cnk(prev == '0' ? nn-1 : nn, cnt);
                        nn -= cnt;
                        cnt = 1;
                        prev = s[id]; 
                    }
                }

                return res;
            }

            return 0;
        }
         
        int &ans = dp[i][number];
        
        if (ans != -1)
            return ans;
        
        int start = !i ? 1 : 0;

        ans = 0;
        
        for (int x=start ; x<10 ; x++) {
            ans += rec(i+1, number*10 + x, n, k);
        }
        
        return ans;
    }
    
    long long countGoodIntegers(int n, int k) {
        memset(dpCnk, -1, sizeof dpCnk);
        cnk(10, 10);
        
        memset(dp, -1, sizeof dp);
        return rec(0, 0, n, k);
    }
};

int main() {
    int k = 5;
    cout<<"res ="<<Solution().countGoodIntegers(2, 1)<<endl;
}