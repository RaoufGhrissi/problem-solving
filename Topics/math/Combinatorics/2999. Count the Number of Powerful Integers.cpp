#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int dp[16][2];
    int limit;
    ll compute(int i, int na9ast, string &mx, string &toFill) {
        if (i == toFill.size()) return 1;
        
        if (toFill[i] != '-') {
            if (na9ast)
                return 1;
            
            if (toFill[i] < mx[i]) return 1;
            else if (toFill[i] > mx[i]) return 0;
            else return compute(i+1, na9ast, mx, toFill);
        }

        int &ans = dp[i][na9ast];
        
        if (ans != -1)
            return ans;

        if (na9ast) {
            ans = (limit+1) * compute(i+1, na9ast, mx, toFill); 
        } else {
            if (limit < (mx[i]-'0'))
                ans = (limit+1) * compute(i+1, 1, mx, toFill);
            else
                ans = (mx[i]-'0') * compute(i+1, 1, mx, toFill) + compute(i+1, 0, mx, toFill);
        }

        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int l, string s) {
        if (stoll(s) > finish) return 0;

        string ch = to_string(finish);
        limit = l;
        
        string toFill = s;
        while(toFill.size() < ch.size()) {
            toFill = '-' + toFill;
        }

        memset(dp, -1, sizeof dp);
        ll ans = compute(0, 0, ch, toFill);

        if (stoll(s) > (start - 1)) return ans;
        
        toFill = s;
        ch = to_string(start - 1);
        while(toFill.size() < ch.size()) {
            toFill = '-' + toFill;
        }

        memset(dp, -1, sizeof dp);


        return ans - compute(0, 0, ch, toFill);
    }
};

int main() {
    cout<<Solution().numberOfPowerfulInt(10, 1844, 5, "12");
}