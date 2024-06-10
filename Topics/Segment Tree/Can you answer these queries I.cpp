#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define Pair pair<ll,ll>
#define iPair pair<int,int>
#define newL cout<<endl
#define ll_max 1e18
#define pb push_back
#define f first
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define forn(j,n) for (int i=j ; i<n ; i++)

using namespace std;

struct node {
    int sm;
    int ml;
    int mr;
    int mx;

    node() {
        sm = 0;
        ml = -1e9;
        mr = -1e9;
        mx = -1e9;
    }

    node(int a, int b, int c, int d) {
        sm = a;
        ml = b;
        mr = c;
        mx = d;
    }
};

class SegTree {
    public:
        vector<node> tree;
        vector<int> a;

        SegTree(vector<int> v){
            int n = v.size();
            a = v;
            tree.resize(4*n); 
            build(0, 0, n-1);
        }

        node mergee(node l, node r) {
            node res;
            res.ml = max(l.ml, l.sm + r.ml);
            res.sm = l.sm + r.sm;
            res.mr = max(r.mr, r.sm + l.mr);
            res.mx = max({l.mx, r.mx, res.ml, res.mr, r.ml + l.mr});
            return res; 
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = node(a[is], a[is], a[is], a[is]);
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        node get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return node();

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	return mergee(get(qs, qe, left, is, mid), get(qs, qe, right, mid+1, ie));
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
                tree[i] = node(val, val, val, val);
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

int main() {
    FAST;
    //freopen("c.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        SegTree segTree = SegTree(v);

        int q;
        cin>>q;
        for (int i=0 ; i<q ; i++) {
            int a, b, c;
            cin>>b>>c;
            cout<<segTree.get(--b, --c, 0, 0, n-1).mx;
            newL;
        }
    }

    return 0;
}