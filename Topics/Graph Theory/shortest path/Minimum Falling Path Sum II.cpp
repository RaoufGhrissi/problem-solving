#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>
#define inf 1e9

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int dist[n][n];
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                dist[i][j] = inf;
            }
        }

        for (int j=0 ; j<n ; j++) {
            pq.push({0, -1, j});
        }

        int ans = 1e9;
        while(!pq.empty()) {
            vector<int> p = pq.top();
            int d = p[0];
            int i = p[1];
            int j = p[2];
            pq.pop();

            if (i == n-1) {
                ans = min(ans, dist[i][j]);
                break;
            }

            if (j && dist[i+1][j-1] > d + v[i+1][j-1]) {
                dist[i+1][j-1] = d + v[i+1][j-1];
                pq.push({dist[i+1][j-1], i+1, j});
            }

            if (j+1 < n && dist[i+1][j+1] > d + v[i+1][j+1]) {
                dist[i+1][j+1] = d + v[i+1][j-1];
                pq.push({dist[i+1][j+1], i+1, j});
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<Solution().minFallingPathSum(v);
    return 0;
}