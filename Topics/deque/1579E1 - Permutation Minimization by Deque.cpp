#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        deque<int> dq;
        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            if (dq.empty()) {
                dq.push_back(x);
            } else if (dq.front() > x) {
                dq.push_front(x);
            } else {
                dq.push_back(x);
            }
        }

        for (auto &x:dq) {
            cout<<x<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}


