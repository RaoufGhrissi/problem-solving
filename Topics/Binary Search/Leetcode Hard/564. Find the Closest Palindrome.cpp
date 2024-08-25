#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    static const int m = 19;
    ll sz[m];

    int getSize(ll num) {
        int i = 1;
        while(sz[i] < num)
            i++;

        return i;
    }

    string getNum(ll num) {
        int n = getSize(num);
        int cnt = sz[n-1];
        int m = n&1 ? (n+1)/2 : n/2;
        ll order = 1;

        string ans = "";
        for (int i=0 ; i<m ; i++) {
            ll s = 1;
            int l = !i && n>1 ? 9 : 10;

            while(s <= l) {
                if ((cnt + (s * 1ll* pow(10, m-1-i))) >= num)
                    break;

                s++;
            }

            cnt += (s-1) * 1ll* pow(10, m-1-i);
            ans += (!i && n>1 ? s :  s - 1) + '0';
        }

        string comp = "";
        int rest = n-ans.size();
        int i = 0;

        while(rest--) {
            comp += ans[i++];
        }

        reverse(comp.begin(), comp.end());
        return ans + comp;
    }

    bool isGreater(ll num, string &n) {
        string ans = getNum(num);
        return stoll(ans) > stoll(n);
    }

    bool isLesser(ll num, string &n) {
        string ans = getNum(num);
        return stoll(ans) < stoll(n);
    }

    string nearestPalindromic(string s) {
        sz[0] = 0;
        sz[1] = 10;

        for (int i=2 ; i<m ; i++) {
            sz[i] = 9;

            int j = i&1 ? (i+1)/2 : i/2;
            j--;
            while(j>0) {
                sz[i] *= 10;
                j--;
            }

            sz[i] += sz[i-1];
        }

        // nearest greater
        ll i = 0;
        ll j = sz[m-1];

        while(i<j) {
            ll mid = (i+j)/2;

            if (isGreater(mid, s)) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        ll g = stoll(getNum(i));

        // nearsest lower
        i = 0;
        j = sz[m-1];

        while(i<j) {
            ll mid = (i+j+1)/2;

            if (isLesser(mid, s)) {
                i = mid;
            } else {
                j = mid-1;
            }
        }

        ll l = stoll(getNum(i));

        ll nn = stoll(s);

        if (g==nn)
            return to_string(l);

        if (l==nn)
            return to_string(g);

        if (nn-l == g-nn) {
            return to_string(l);
        } else if(nn-l < g-nn) {
            return to_string(l);
        }

        return to_string(g);
    }
};