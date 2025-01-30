#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int m = 101;
        int n = 101;

        vector<vector<int>> v(n, vector<int>(m, 0));
        vector<vector<int>> cum = v;

        vector<vector<pp>> next(n, vector<pp>(m, {-1, -1}));
        
        for (int i=0 ; i<points.size() ; i++) {
            v[points[i][1]][points[i][0]] = 1;
            cum[points[i][1]][points[i][0]] = 1;
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=1 ; j<m ; j++) {
                cum[i][j] += cum[i][j-1];
            }
        }

        for (int j=0 ; j<m ; j++) {
            for (int i=1 ; i<n ; i++) {
                cum[i][j] += cum[i-1][j];
            }
        }


        for (int i=0 ; i<n ; i++) { // line by line
            int prev = -1;
            for (int j=0 ; j<m ; j++) { // col by col
                if (prev == -1) prev = j;
                else {
                    if (!v[i][j]) continue;
                    next[i][prev].second = j;
                    prev = j;
                }
            }
        }

        for (int j=0 ; j<m ; j++) {
            int prev = -1;
            for (int i=0 ; i<n ; i++) {
                if (prev == -1) prev = i;
                else {
                    if (!v[i][j]) continue;
                    next[prev][j].first = i;
                    prev = i;
                }
            }
        }

        ll ans = -1;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                auto [ii, jj] = next[i][j];

                if (ii == -1 || jj == -1) continue;
                if (!v[ii][jj]) continue;

                int cnt = cum[ii][jj];

                if (i) {
                    cnt -= cum[i-1][jj];
                }

                if (j) {
                    cnt -= cum[ii][j-1];
                }

                if (i && j) {
                    cnt += cum[i-1][j-1];
                }

                if (cnt != 4) continue;

                ans = max(ans, 
                    (ii - i) * 1ll * (jj - j)
                );
            }
        }

        return ans;
    }
};