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
        const static int N = 3*1e4;
        int tree[4*N];

        SegTree(int n){
            build(0, 0, n-1);
        }

        int mergee(int l, int r) {
            return l+r;
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = 0;
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
                return 0;

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
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v;
        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            v.pb({x, -1, -1, i});
        }

        int q;
        cin>>q;
        vector<int> ans(q);
        for (int i=0 ; i<q ; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            v.pb({c, --a, --b, i});
        }

        sort(v.begin(), v.end(), greater<vector<int>>());

        SegTree segTree = SegTree(n);
        for (auto a:v) {
            if (a[1] == -1) // not a query
                segTree.update(a[3], 1, 0, 0, n-1);
            else
                ans[a[3]] = segTree.get(a[1], a[2], 0, 0, n-1);
        }

        for (int i=0 ; i<q ; i++)
            cout<<ans[i]<<endl;
    }

    return 0;
}
