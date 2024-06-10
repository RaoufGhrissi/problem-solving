#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll,ll>
#define inf 1e18
#define st pair<int, pair<int, set<int>>>

//https://codeforces.com/contest/1945/problem/G

using namespace std;

struct Child {
    int p;
    int t;
    int id;
    int entry;

    Child(int _p, int _t, int _id, int e) {
        p = _p;
        t = _t;
        id = _id;
        entry = e;
    }

    bool operator<(const Child &other) const {
        if (p == other.p) {
            if (entry == other.entry)
                return t > other.t;

            return entry > other.entry;
        }

        return p < other.p;
    }
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, d;
        cin>>n>>d;

        vector<int> priority(n);
        vector<int> time(n);
        vector<vector<int>> back(d+1);

        priority_queue<Child> pq;
        queue<int> q;

        for (int i=0 ; i<n ; i++) {
            cin>>priority[i]>>time[i];
            q.push(i);
        }

        vector<int> mx(n, 0);
        for (int i=n-1 ; i>-1 ; i--) {
            mx[i] = priority[i];
            if (i+1<n)
                mx[i] = max(mx[i], mx[i+1]);
        }

        int ans = -1;
        for (int i=1 ; i<=d ; i++) {
            for (auto &b:back[i])
                pq.push(Child(priority[b], time[b], b, i));

            int t = q.front();
            if (!pq.empty() && pq.top().p > mx[t]) {
                t = pq.top().id;
                pq.pop();
            } else {
                q.pop();
            }

            if (q.empty()) {
                ans = i;
                break;
            }

            int r = i + time[t] + 1;
            if (r <= d)
                back[r].push_back(t);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}