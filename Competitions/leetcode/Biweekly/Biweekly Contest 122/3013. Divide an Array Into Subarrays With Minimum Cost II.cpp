#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long minimumCost(vector<int>& v, int k, int dist) {
        int n = v.size();
        vector<bool> used(n, 0);
        multiset<pair<ll,int>> st;
        priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        ll ans = 1e15;
        ll sm = 0;
        int last_possible = n-1;
        //int dist = n+1; for v1
        //int k = 3; for v1
        k--;

        for (int i=n-1 ; i>0 ; i--) {
            if (last_possible - i > dist) {
                if (used[last_possible]) {
                    sm -= v[last_possible];
                    st.erase(st.lower_bound({v[last_possible], last_possible}));
                }
                last_possible--;
            }

            while (!pq.empty() && st.size() < k) {
                if (pq.top().second <= last_possible) {
                    st.insert(pq.top());
                    sm += pq.top().first;
                }
                pq.pop();
            }

            if (st.size() < k) {
                used[i] = 1;
                st.insert({v[i], i});
                sm += v[i];
            } else {
                pair<int,int> mx = *st.rbegin();
                if (mx.first > v[i]) {
                    used[mx.second] = 0;
                    sm -= mx.first;
                    st.erase(st.lower_bound(mx));
                    used[i] = 1;
                    sm += v[i];
                    st.insert({v[i], i});
                } else {
                    pq.push({v[i], i});
                }
            }

            if (st.size() == k)
                ans = min(ans, sm);
        }

        return ans + v[0];
    }
};

int main() {
    vector<int> v = {1,3,2,6,4,2};
    cout<<Solution().minimumCost(v, 3, 3);
}