#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[1000][1000];
    int cum[10000];
    int k, n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> next, copy;

    bool safe(int i, int j) {
        return i>-1 && j>-1 && i<n && j<m;
    }

    vector<int> maxPoints(vector<vector<int>>& v, vector<int>& q) {
        k = q.size();
        n = v.size();
        m = v[0].size();

        vector<int> ans(k);

        vector<vector<int>> qq(k);
        for (int i=0 ; i<k ; i++) {
            qq[i] = {q[i], i};
        }

        sort(qq.begin(), qq.end());
        memset(vis, 0, sizeof vis);
        memset(cum, 0, sizeof cum);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({v[0][0], 0, 0});
        vis[0][0] = 1;
        int p = 0;

        while(p<k && !pq.empty()) {
            auto t = pq.top();
            if (t[0] >= qq[p][0]) {
                p++;
                continue;
            }

            pq.pop();
            
            int i = t[1];
            int j = t[2];

            cum[p]++;
            
            for (int d=0 ; d<4 ; d++) {
                int di = i+dx[d];
                int dj = j+dy[d];

                if (safe(di, dj) && !vis[di][dj]) {
                    vis[di][dj] = 1;
                    pq.push({v[di][dj], di, dj});    
                }
            }
        }
        
        for (int i=0 ; i<k ; i++) {
            if (i)
                cum[i] += cum[i-1];

            ans[qq[i][1]] = cum[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> q = {5, 6, 2};
    vector<int> ans = s.maxPoints(v, q);
    for (auto x:ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}