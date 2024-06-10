#include <bits/stdc++.h>

using namespace std;

class Compressor {
    public:
        set<int> v;
        map<int, int> match;
        map<int, int> inversedMatch;
        int last;

    Compressor(vector<int> a) {
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

        BIT(vector<int> v) {
            tree = v;
            n = v.size();
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] = max(tree[x], val);
                x+=(x)&(-x);
            }
        }

        int get_max(int x)
        {
            int res=0;
            while(x>0)
            {
                res = max(tree[x], res);
                x-=(x)&(-x);
            }

            return res;
        }
};

int solve() {
    int k;
    cin>>k;

    vector<int> v(k);
    for (int i=0 ; i<k ; i++)
        cin>>v[i];

    Compressor comp = Compressor(v);
    int n = comp.last;
    vector<int> a(n, 0);
    BIT bit = BIT(a);

    int ans = 0;
    for (int i=0 ; i<k ; i++) {
        int m = comp.match[v[i]];
        int mx = bit.get_max(m-1);
        bit.update(m, mx+1);
    }

    return bit.get_max(n-1);
}

int main() {
    cout<<solve();

    return 0;
}