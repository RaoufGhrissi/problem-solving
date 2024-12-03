#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int m = 100, inf = 1e5 + 7;
    int dist[m][m];
    int findTheCity(int n, vector<vector<int>>& e, int d) {
        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
                dist[i][j] = inf;
        }

        for (auto a:e) {
            dist[a[0]][a[1]] = a[2];
            dist[a[1]][a[0]] = a[2];
        }

        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                for (int k=0 ; k<n ; k++)
                {
                    if (dist[j][i] + dist[i][k] < dist[j][k])
                        dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }

        int ans=-1, mi=inf, sm;
        for (int i=0 ; i<n ; i++)
        {
            sm = 0;
            for (int j=0 ; j<n ; j++)
                sm += i != j && dist[i][j] <= d;

            if (sm <= mi)
            {
                mi = sm;
                ans = i;
            }
        }

        return ans;

    }
};