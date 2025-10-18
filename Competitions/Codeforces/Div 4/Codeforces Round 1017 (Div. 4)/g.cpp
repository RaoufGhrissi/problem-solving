#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int q;
        cin>>q;


        deque<ll> dq;
        bool normalOrder = 1;

        ll normalSum = 0;
        ll reverseSum = 0;
        ll sm = 0;
        ll cnt = 0;

        while(q--) {
            int tp;
            cin>>tp;

            if (tp == 3) {
                ll k;
                cin>>k;
                sm += k;
                cnt++;

                if (normalOrder)
                    dq.push_back(k);
                else
                    dq.push_front(k);

                normalSum += cnt*k;
                reverseSum += sm;
            } else if (tp == 2) {
                swap(normalSum, reverseSum);
                normalOrder = !normalOrder;                
            } else {
                int last = normalOrder ? dq[cnt-1] : dq[0];
                normalSum += sm - last;
                normalSum -= (cnt-1)*last;

                reverseSum -= sm;
                reverseSum += last;
                reverseSum += (cnt-1)*last;

                if (normalOrder) {
                    dq.pop_back();
                    dq.push_front(last);
                } else {
                    dq.pop_front();
                    dq.push_back(last);
                }
            }

            cout<<normalSum<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}