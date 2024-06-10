#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

using namespace std;

class Compressor {
    public:
        set<ll> v;
        map<ll, ll> match;
        map<ll, ll> inversedMatch;
        ll last;

    Compressor(vector<ll> a) {
        for (auto &e:a)
            v.insert(e);
        
        build();
    }

    void build() {
        last = 1;
        for (auto &a: v) {
            match[a] = last;
            inversedMatch[last] = a;
            last++;
        }
    }
};

class BIT {
    public:
        vector<int> tree;
        int n;

        BIT(int k) {
            n = k;
            tree.resize(n);
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] += val;
                x+=(x)&(-x);
            }
        }

        int get(int x)
        {
            int res=0;
            while(x>0)
            {
                res += tree[x];
                x-=(x)&(-x);
            }

            return res;
        }
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> p(n);

        for (int i=0; i<n ; i++)
            cin>>v[i];

        for (int i=0; i<n ; i++)
            cin>>p[i];

        Compressor comp = Compressor(v);
        int m = comp.last;

        BIT bit = BIT(m);
        for (auto &a:v) {
            bit.update(comp.match[a], 1);
        }

        ll ans = 0, kk;
        for (int k=1 ; k<=n ; k++) {
            if (k>1) {
                bit.update(comp.match[v[p[k-2]-1]], -1);
            }

            int i = 1;
            int j = m-1;

            while(i<j) {
                int mid = (i+j+1)/2;
                ll cnt = bit.get(m-1) - bit.get(mid-1);
                if (cnt < k) {
                    j = mid-1;
                } else {
                    i = mid;
                }
            }

            if ((bit.get(m-1) - bit.get(i-1)) >= k && k*comp.inversedMatch[i] > ans) {
                ans = k*comp.inversedMatch[i];
                kk = k;
            }
        }

        cout<<ans<<" "<<kk<<endl;
    }
}

int main() {
    solve();
    return 0;
}