#include <bits/stdc++.h>
#define inf (int)1e9;
using namespace std;

//https://leetcode.com/problems/freedom-trail/description/

class Solution {
public:
    int findRotateSteps(string s, string key) {
        int n = key.size();
        int m = s.size();
        vector<vector<int>> pos(26);

        for (int i=0 ; i<m ; i++)
            pos[s[i]-'a'].push_back(i);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int dist[n][m];
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++)
                dist[i][j] = inf;
        }

        pq.push({dist[0][0], 0, 0});

        while(!pq.empty()) {
            vector<int> p = pq.top();
            pq.pop();
            
            int d = p[0];
            int index = p[1];
            int i = p[2];

            if (dist[i][index] > d) continue;


            if (d == (int)1e9) d = 0;

            for (auto &id:pos[key[i]-'a']) {
                int dd = min(m-id, id) + 1;
                if (dd + d < dist[i][id]) {
                    dist[i][id] = dd + d;
                    pq.push({dist[i][id], id, i+1}); 
                }
            }
        }

        int ans = 1e9;

        for (int i=0 ; i<n ; i++) {
            ans = min(ans, dist[n-1][i]);
        }

        return ans;
    }
};

int main() {
    cout<<Solution().findRotateSteps("godding", "gd");
}