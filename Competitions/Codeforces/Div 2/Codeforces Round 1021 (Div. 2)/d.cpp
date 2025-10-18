#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
#define mod 1000000007
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

const int N = 1001;
int mat[N][N];

bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

bool canGo(int x, int y, int a, int b, int n, int m) {
    for (int d=0 ; d<4 ; d++) {
        int xx = x+dx[d];
        int yy = y+dy[d];

        if (safe(xx, yy, n, m) && xx == a && yy == b)
            return 1;
    }

    return 0;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                mat[i][j] = 0;
            }
        }

        vector<pp> v(k);

        for (int i=0 ; i<k ; i++) {
            cin>>v[i].first>>v[i].second;
            v[i].first--;
            v[i].second--;
        }

        ll ans = 1;
        for (int i=0 ; i<k-1 ; i++) {
            ll cnt = 0;
            for (int d=0 ; d<4 ; d++) {
                int x = v[i].first + dx[d];
                int y = v[i].second + dy[d];

                int nxtX = v[i+1].first;
                int nxY = v[i+1].second;

                if (safe(x, y, n, m) && canGo(x, y, nxtX, nxtX, n, m)) {
                    cnt++;
                }
            }

            ans = (ans * cnt)%mod;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}