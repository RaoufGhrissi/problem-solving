#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

class Solution {
public:
    static const int inf = 1e4 + 5;
    static const int N = 101;
    int dist[N];
    vector<pair<int,int>> graph[N];

    void dijkistra(int p)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, p});
        dist[p] = 0;

        while(!pq.empty())
        {
            pair<int,int> x = pq.top();
            pq.pop();
            int w = x.first;
            int c = x.second;
           
            if (w > dist[c])
                continue;

            for (auto child:graph[c])
            {
                if (dist[c] + child.second < dist[child.first]) {
                    dist[child.first] = dist[c] + child.second;
                    pq.push({dist[c] + child.second, child.first});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        for (auto a:v)
            graph[a[0]].push_back({a[1], a[2]});

        for (int i=1 ; i<=n ; i++)
            dist[i] = inf;

        dijkistra(k);
        int ans = 0;
        for (int i=1 ; i<=n ; i++) {
            if (dist[i] == inf) return -1;
            if (i != k)
                ans = max(ans, dist[i]);
        }

        return ans;
    }
};