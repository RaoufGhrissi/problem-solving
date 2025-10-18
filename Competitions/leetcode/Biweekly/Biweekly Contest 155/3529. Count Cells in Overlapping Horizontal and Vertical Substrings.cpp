#include <bits/stdc++.h>

using namespace std;

class StringHashing {
    public:
        /*
            4 possible values => first 2 primes greater than 4 are 5 and 7 => a1=5 a2=7;
            h[0] = s[0]-'A'
            h[k] = (h[k-1]*a + s[k]-'A')%m

            p[0] = 1        
            p[k] = (p[k-1]*a)%m

            substr(a, b) = (h[b] - h[a-1]*p[b-a+1])%m
        */

        int a1 = 5, a2 = 7, m1 = 1e9 + 7, m2 = 1e9 + 9;
        vector<int> k1;
        vector<int> k2;
        vector<int> p1;
        vector<int> p2;
        string s;
        int n;

        StringHashing(string str) {
            s = str;
            n = s.size();
            k1.resize(n);
            k2.resize(n);
            p1.resize(n);
            p2.resize(n);

            fill(k1.begin(), k1.end(), 0);
            fill(k2.begin(), k2.end(), 0);
            fill(p1.begin(), p1.end(), 0);
            fill(p2.begin(), p2.end(), 0);
        
            build();
        }

        void generate_hash_data(vector<int> &k, vector<int> &p, int a, int m)
        {
            k[0] = s[0]-'a'+1;
            p[0] = 1;
            int n = s.size();
            for (int i=1 ; i<n ; i++)
            {
                k[i] = (k[i-1]*1ll*a + s[i]-'a'+1)%m;
                p[i] = (p[i-1]*1ll*a)%m;
            }
        }

        void build() {
            int n = s.size();
            generate_hash_data(k1, p1, a1, m1);
            generate_hash_data(k2, p2, a2, m2);
        }

        int get(vector<int> &k, vector<int> &p, int &m, int a, int b) {
            int res = k[b];
            if (a)
                res = (res - k[a-1]*1ll*p[b-a+1])%m;

            if (res < 0)
                res += m;

            return res;
        }

        int get1(int a, int b) {
            return get(k1, p1, m1, a, b);
        }

        int get2(int a, int b) {
            return get(k2, p2, m2, a, b);
        }
};

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        string h, v;

        int n = grid.size();
        int m = grid[0].size();

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                h += grid[i][j];
            }
        }

        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                v += grid[j][i];
            }
        }

        vector<int> cumH(n*m, 0), cumV(n*m, 0);

        StringHashing hh = StringHashing(h), hv = StringHashing(v), hp = StringHashing(pattern);

        int sz = h.size();
        int ps = pattern.size();
        for (int i=0 ; i+ps-1<sz ; i++) {
            if (hh.get1(i, i+ps-1) == hp.get1(0, ps-1) && hh.get2(i, i+ps-1) == hp.get2(0, ps-1)) {
                cumH[i] += 1;
                if (i+ps < sz)
                    cumH[i+ps] -= 1; 
            }
        }

        for (int i=0 ; i+ps-1<sz ; i++) {
            if (hv.get1(i, i+ps-1) == hp.get1(0, ps-1) && hv.get2(i, i+ps-1) == hp.get2(0, ps-1)) {
                cumV[i] += 1;
                if (i+ps < sz)
                    cumV[i+ps] -= 1; 
            }
        }

        vector<vector<bool>> g(n, vector<bool>(m, 1));

        for (int i=0 ; i<sz ; i++) {
            if (i) {
                cumH[i] += cumH[i-1];
                cumV[i] += cumV[i-1];
            }

            int line = i/m;
            int col = i%m;

            if (cumH[i] == 0)
                g[line][col] = 0;

            col = i/n;
            line = i%n;

            if (cumV[i] == 0)
                g[line][col] = 0;
        }

        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                ans += g[i][j];
            }
        }

        return ans;

    }
};