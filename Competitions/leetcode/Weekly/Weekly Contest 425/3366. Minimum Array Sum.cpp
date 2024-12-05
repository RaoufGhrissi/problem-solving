#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int dp[100][101][101];

    int rec(int i, int op1, int op2, vector<int> &v, int &k) {
        if (i == v.size())
            return 0;

        int &ans = dp[i][op1][op2];
        
        if (ans != -1)
            return ans;

        ans = v[i] + rec(i+1, op1, op2, v, k); // mana3mel hata operation, nhez l v[i] kima heya, ops mano9souch
        
        // op1
        if (op1 > 0) {
            int nb = v[i]/2;
            if (v[i]%2) nb++;

            ans = min(ans, nb + rec(i+1, op1-1, op2, v, k)); // jareb op1

            if (op2 > 0 && nb >= k) { // jareb op1 then op2
                ans = min(ans, nb-k + rec(i+1, op1-1, op2-1, v, k));
            }
        }

        // op2
        if (op2 > 0 && v[i] >= k) {
            int nb = v[i]-k;
            ans = min(ans, nb + rec(i+1, op1, op2-1, v, k));

            if (op1 > 0) { // op2 then op1
                int nb2 = nb/2;
                if (nb&1) nb2++;

                ans = min(ans, nb2 + rec(i+1, op1-1, op2-1, v, k));
            }
        }

        return ans;
    }

    int minArraySum(vector<int>& v, int k, int op1, int op2) {
        memset(dp, -1, sizeof dp);

        return rec(0, op1, op2, v, k);
    }
};  