#include <bits/stdc++.h>
#define ll long long

using namespace std;

class MatrixExp {
    public:
        vector<vector<ll>> mat;
        const static int mod = 1e9 + 7;
        int n, m;
        
        MatrixExp(int _n, int _m) {
            n = _n;
            m = _m;

            mat.resize(n);
            for (int i=0 ; i<n ; i++)
                mat[i].resize(m);

            for (int i=0 ; i<n ; i++) {
                for (int j=0 ; j<m ; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        MatrixExp friend operator *(const MatrixExp &a, const MatrixExp &b){
            MatrixExp c(a.n, b.m);
            for (int i = 0; i < c.n; i++) {
                for (int j = 0; j < c.m; j++) {
                    c.mat[i][j] = 0;
                    for (int k = 0; k < a.m; k++) {
                        c.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%mod;
                        c.mat[i][j] %= mod;
                    }
                }
            }
            return c;
        }

        MatrixExp compute(int t, MatrixExp &base) {
            MatrixExp ans(26, 26);
            for (int i=0 ; i<ans.n ; i++) {
                for (int j=0 ; j<ans.m ; j++) {
                    ans.mat[i][j] = i==j ? 1 : 0;
                }
            }

            while(t>0) {
                if (t&1)
                    ans = ans * base;

                base = base * base;
                t >>=1;
            }

            return ans;
        }
};

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& v) {
        MatrixExp base(26, 26);

        for (int i=0 ; i<26 ; i++) {
            int x = v[i];
            int s = i+1;
            while(x--) {
                s %= 26;
                base.mat[i][s] = 1;
                s++;
            }
        }

        MatrixExp occ(1, 26);

        for (char &c:s) {
            occ.mat[0][c-'a']++;
        }

        occ = occ * occ.compute(t, base);

        int res = 0;

        for (int i=0 ; i<26 ; i++) {
            res += occ.mat[0][i];
            res %= occ.mod;
        }

        return res;
    }
};