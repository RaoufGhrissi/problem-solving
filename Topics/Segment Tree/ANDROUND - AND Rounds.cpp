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

#define pp pair<int,int>
#define f first
#define s second

class SegTree {
    public:
        vector<int> a;
        vector<int> tree;

        SegTree(vector<int> v){
            int n = v.size();
            a = v;
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        int mergee(int l, int r) {
            return l&r;
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = a[is];
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        int get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return (1<<32) - 1;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	int l = get(qs, qe, left, is, mid);
        	int r = get(qs, qe, right, mid+1, ie);
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

int main() {
    FAST;
    //freopen("c.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        SegTree segTree = SegTree(v);

        k = min(k, n);
        for (int i=0 ; i<n ; i++) {
            int x = segTree.get(max(0, i-k), min(n-1, i+k), 0, 0, n-1);
            if (i-k < 0)
                x &= segTree.get(n+(i-k), n-1, 0, 0, n-1);

            if (i+k > n-1)
                x &= segTree.get(0, i+k-n, 0, 0, n-1);

            cout<<x<<" ";
        }
        newL;
    }

    return 0;
}