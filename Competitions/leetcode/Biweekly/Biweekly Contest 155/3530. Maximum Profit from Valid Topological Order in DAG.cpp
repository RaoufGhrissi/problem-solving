#include <bits/stdc++.h>

#define pp pair<int,int>

using namespace std;

class Solution {
public:
    static const int N = 22;
    vector<int> graph[N];

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> in(n, 0);

        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i=0 ; i<n ; i++) {
            if (!in[i]) {
                pq.push({score[i], i});
            }
        }

        int ans = 0;
        int cnt = 1;

        while(!pq.empty()) {
            pp mi = pq.top();
            pq.pop();

            ans += cnt*mi.first;
            cnt++;

            int node = mi.second;

            cout<<node<<endl;

            for (int &child:graph[node]) {
                in[child]--;
                if (!in[child]) {
                    pq.push({score[child], child});
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> edges = {{1,2},{0,3},{1,4},{2,3},{1,3}};
    vector<int> scores = {50913,47946,97391,27488,69147};
    cout<<Solution().maxProfit(5, edges, scores);
}