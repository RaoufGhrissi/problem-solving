#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

#define ll long long

class Solution {
public:
    ll maxScore(vector<int>& v) {
        ll ans = 0;
        ll g = 0, m=0;
        for (int j=0 ; j<v.size() ; j++) {
            g = !g ? v[j] : gcd(g, v[j]);
            m = !m ? v[j] : lcm(m, v[j]);
        }
        

        ans = max(ans, g*m);

        for (int i=0 ; i<v.size() ; i++) {
            g = 0, m=0;
            for (int j=0 ; j<v.size() ; j++) {
                if (i==j) continue;

                g = !g ? v[j] : gcd(g, v[j]);
                m = !m ? v[j] : lcm(m, v[j]);
            }

            ans = max(ans, g*m);
        }

        return ans;
    }
};