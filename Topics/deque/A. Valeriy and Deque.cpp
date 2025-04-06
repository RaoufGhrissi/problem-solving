#include <bits/stdc++.h>
#define pp pair<ll, int>
#define ll long long

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int n, q;

    cin>>n>>q;
    vector<pp> qs;

    deque<int> dq;

    int mx = 0;

    for (int i=0 ; i<n ; i++) {
        int x;
        cin>>x;

        mx = max(mx, x);
        dq.push_back(x);
    }

    for (int i=0 ; i<q ; i++) {
        ll x;
        cin>>x;
        qs.push_back({x, i});
    }

    vector<pp> ans(q);
    sort(qs.begin(), qs.end());

    int qId = 0;
    int i = 1;

    while(qId < q && dq.front() != mx) {
        while (i==qs[qId].first) {
            ans[qs[qId].second] = {dq[0], dq[1]};
            qId++;
        }

        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();

        dq.push_back(min(a, b));
        dq.push_front(max(a, b));

        i++;
    }

    while(qId < q) {    
        ll nb = qs[qId].first - i;
        ll r = nb%(n-1);

        ans[qs[qId].second] = {mx, dq[1+r]};
        qId++;
    }

    for (int j=0 ; j<q ; j++) {
        cout<<ans[j].first<<" "<<ans[j].second<<endl;
    }
}

int main() {
    solve();
    return 0;
}


