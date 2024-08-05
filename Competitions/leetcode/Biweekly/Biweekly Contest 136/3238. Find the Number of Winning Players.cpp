#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<int,int>
#define INF (ll)1e18

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& v) {
        int pick[15][15] = {0};

        for (auto &e:v)
            pick[e[0]][e[1]]++;

        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<15 ; j++) {
                if (pick[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};