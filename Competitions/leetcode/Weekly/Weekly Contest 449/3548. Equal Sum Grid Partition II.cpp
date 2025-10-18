#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    static const int N = 1e5 + 1;
    bool canPartitionGrid(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<int> occ(N, 0), prev(N, 0), next(N, 0);
        ll tot = 0, t = 0;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                tot += v[i][j];
                occ[v[i][j]]++;
                next[v[i][j]]++;
            }
        }

        t = tot;

        // vertical cut
        ll cum = 0;
        for (int i=0 ; i<m-1 ; i++) {
            for (int j=0 ; j<n ; j++) {
                prev[v[j][i]]++;
                cum += v[j][i];
                tot -= v[j][i];
                next[v[j][i]]--;
            }

            if (tot == cum) {
                return 1;
            } else if (tot > cum) {
                if (i == m-2) {
                    if ((cum == tot-v[0][m-1]) || (cum == tot-v[n-1][m-1]))
                        return 1;
                } else {
                    ll diff = tot-cum;

                    if (n == 1) {
                        if (diff == v[0][m-1] || diff == v[0][i+1])
                            return 1;
                    } else if (diff < N && next[diff] > 0) {
                        return 1;
                    }
                }
            } else {
                if (i == 0) {
                    if ((tot == cum-v[0][0]) || (cum == tot-v[n-1][0]))
                        return 1;
                } else {
                    ll diff = -tot+cum;

                    if (n == 1) {
                        if (diff == v[0][0] || diff == v[0][i])
                            return 1;
                    } else if (diff < N && prev[diff] > 0) {
                        return 1;
                    }
                }
            }
        }

        for (int i=0 ; i<N ; i++) {
            next[i] = occ[i];
            prev[i] = 0;
        }

        // horizental cut
        cum = 0;
        tot = t;
        for (int i=0 ; i<n-1 ; i++) {
            for (int j=0 ; j<m ; j++) {
                prev[v[i][j]]++;
                cum += v[i][j];
                tot -= v[i][j];
                next[v[i][j]]--;
            }

            if (tot == cum) {
                return 1;
            } else if (tot > cum) {
                if (i == n-2) {
                    if ((cum == tot-v[n-1][0]) || (cum == tot-v[n-1][m-1]))
                        return 1;
                } else {
                    ll diff = tot-cum;

                    if (m == 1) {
                        if (diff == v[i+1][0] || diff == v[n-1][0])
                            return 1;
                    } else if (diff < N && next[diff] > 0) {
                        return 1;
                    }
                }
            } else {
                if (i == 0) {
                    if ((tot == cum-v[0][0]) || (cum == tot-v[0][m-1]))
                        return 1;
                } else {
                    ll diff = -tot+cum;

                    if (n == 1) {
                        if (diff == v[0][0] || diff == v[i][0])
                            return 1;
                    } else if (diff < N && prev[diff] > 0) {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};


int main() {
    vector<vector<int>> v = {{10, 5, 4, 5}}; // {{10930}, {96950}, {100000}}; // {{1, 2, 4}, {2, 3, 5}};
    cout<<Solution().canPartitionGrid(v);
}
