#include <bits/stdc++.h>

using namespace std;

#define pq priority_queue<ll, vector<ll>, greater<ll>>

#define ll long long

class Solution {
public:
    vector<ll> ans;

    pair<pq, pq> dfs(int i, int p, vector<vector<int>>& graph, vector<int>& cost) {
        pq pos, neg;
        if (cost[i] > 0)
            pos.push(cost[i]);
        else
            neg.push(-cost[i]);

        for (auto &child:graph[i]) {
            if (child == p) continue;

            auto pp = dfs(child, i, graph, cost);

            pq res = pp.first;
            while(!res.empty()) {
                ll t = res.top();

                res.pop();

                if(pos.size() < 3) {
                    pos.push(t);
                }
                else if(pos.top() < t) {
                    pos.pop();
                    pos.push(t);
                }
            }

            res = pp.second;
            while(!res.empty()) {
                ll t = res.top();

                res.pop();

                if(neg.size() < 3) {
                    neg.push(t);
                }
                else if(neg.top() < t) {
                    neg.pop();
                    neg.push(t);
                }
            }
        }

        ans[i] = 1;
        if (!neg.size()) {
            if (pos.size() == 3) {
                ll t1 = pos.top();
                pos.pop();
                ll t2 = pos.top();
                pos.pop();
                ans[i] = t1*t2*pos.top();
                pos.push(t1);
                pos.push(t2);
            }
        } else if (neg.size() == 1) {
            if (pos.size() > 1) {
                ll t1 = pos.top();
                pos.pop();
                ll t2 = pos.top();
                pos.pop();
                if (pos.empty())
                    ans[i] = 0;
                else
                    ans[i] = t1*t2*pos.top();

                pos.push(t1);
                pos.push(t2);
            }
        } else if (neg.size() == 2) {
            if (pos.size() > 0) {
                ll t1 = neg.top();
                neg.pop();
                ll t2 = neg.top();
                neg.push(t1);

                ll negTot = t1*t2;

                if (pos.size() == 1)
                    ans[i] = negTot*pos.top();
                else if (pos.size() == 2) {
                    t1 = pos.top();
                    pos.pop();
                    ans[i] = negTot*pos.top();
                    pos.push(t1);
                } else {
                    t1 = pos.top();
                    pos.pop();
                    t2 = pos.top();
                    pos.pop();

                    ans[i] = pos.top()*max(t1*t2, negTot);

                    pos.push(t1);
                    pos.push(t2);
                }
            }
        } else {
            if (!pos.size()) {
                ans[i] = 0;
            } else {
                ll t1 = neg.top();
                neg.pop();
                ll t2 = neg.top();
                neg.pop();
                ll negTot = neg.top()*t2;
                neg.push(t1);
                neg.push(t2);

                if (pos.size() == 1)
                    ans[i] = negTot*pos.top();
                else if (pos.size() == 2) {
                    t1 = pos.top();
                    pos.pop();
                    ans[i] = negTot*pos.top();
                    pos.push(t1);
                } else {
                    t1 = pos.top();
                    pos.pop();
                    t2 = pos.top();
                    pos.pop();

                    ans[i] = pos.top()*max(t1*t2, negTot);

                    pos.push(t1);
                    pos.push(t2);
                }
            }
        }

        return {pos, neg};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> graph(n);

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        ans.resize(n);
        dfs(0, -1, graph, cost);
        return ans;
    }
};