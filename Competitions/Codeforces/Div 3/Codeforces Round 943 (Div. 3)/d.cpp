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
        int pb, ps, n, k;
        cin>>n>>k>>pb>>ps;

        pb--;
        ps--;

        vector<ll> p(n);
        vector<ll> a(n);

        for (int i=0 ; i<n ; i++)
        {
            cin>>p[i];
            p[i]--;
        }

        for (int i=0 ; i<n ; i++)
        {
            cin>>a[i];
        }

        int kk = k;
        map<int,bool> vis;

        ll mxB = 0;
        vector<ll> score;
        int m = 0;
        while(!vis.count(pb) && kk > 0) {
            ll prev = (m > 0 ? score[m-1] : 0);
            mxB = max(mxB, prev + kk*a[pb]);
            score.push_back(prev + a[pb]);
            vis[pb] = 1;
            pb = p[pb];
            kk--;
            m = score.size();
        }

        if (kk) {
            ll q = kk/m;
            ll r = kk%m;
            max(mxB, score[m-1]*q + score[r-1]);
        }

        ll scoreB = mxB;

        // Sasha

        kk = k;
        vis.clear();

        mxB = 0;
        score.clear();
        m = 0;
    
        while(!vis.count(ps) && kk) {
            ll prev = (m > 0 ? score[m-1] : 0);
            mxB = max(mxB, prev + kk*a[ps]);
            score.push_back(prev + a[ps]);
            vis[ps] = 1;
            ps = p[ps];
            kk--;
            m = score.size();
        }

        if (kk) {
            ll q = kk/m;
            ll r = kk%m;
            max(mxB, score[m-1]*q + score[r-1]);
        }

        ll scoreS = mxB;

        if (scoreB == scoreS) {
            cout<<"Draw";
        } else if (scoreB > scoreS) {
            cout<<"Bodya";
        } else {
            cout<<"Sasha";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}