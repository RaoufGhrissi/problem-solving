#include <bits/stdc++.h>

using namespace std;

#define ll long long

class SegTree {
    public:
        vector<int> v;
        vector<int> tree;
        int n;

        SegTree(vector<int> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        ll mergee(ll l, ll r) {
            return max(l, r);
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = v[ie];
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        ll get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return -1;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	ll l = get(qs, qe, left, is, mid);
        	ll r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i] = val;
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	update(index, val, left, is, mid);
        	update(index, val, right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }
};

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n), b(n);

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }

        for (int i=0 ; i<n ; i++) {
            cin>>b[i];
        }


        int mxValue = 2*n + 1;
        vector<int> s(mxValue, -1);

        SegTree seg = SegTree(s);       
        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            int target = b[i];

            if (target == a[i]) {
                ll before = i+1;
                ll after = n-i;

                ans += before * after;
            } else {
                target = max(target, a[i]);
                int lastIndex = seg.get(target, mxValue - 1, 0, 0, mxValue - 1);
                
                if (lastIndex > -1) {
                    ll before = lastIndex+1;
                    ll after = n-i;

                    ans += before * after;
                }
            }

            seg.update(a[i], i, 0, 0, mxValue - 1);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}