#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Compressor {
    public:
        set<ll> v;
        map<ll, int> match;
        map<int, ll> inversedMatch;
        int last;

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

class SegTree {
    public:
        vector<ll> v;
        vector<ll> tree;
        int n;

        SegTree(vector<ll> a){
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
                return -2;

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
        		tree[i] = max(tree[i], val*1ll);
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

class Solution {
public:
    int shortestSubarray(vector<int>& t, int k) {
        vector<ll> c = {0ll};

        vector<ll> v(t.begin(), t.end());

        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            if (v[i] == k) return 1;
            if (i) v[i] += v[i-1];

            c.push_back(v[i]);
            c.push_back(v[i]-k);
        }

        Compressor comp = Compressor(c);

        vector<ll> a(comp.last, -2);
        a[comp.match[0]] = -1;
        
        SegTree segTree = SegTree(a);

        int ans = 1e9;
        for (int i=0 ; i<n ; i++) {
            int x = comp.match[v[i]-k];
            int mx = segTree.get(0, x, 0, 0, a.size() - 1);

            if (mx > -2)
                ans = min(ans, i-mx);

            segTree.update(comp.match[v[i]], i, 0, 0, a.size() - 1);
        }

        return ans == 1e9 ? -1 : ans;
    }
};

// can also be done with heap

class Solution {
public:
    int shortestSubarray(vector<int>& t, int k) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        pq.push({0, -1});

        vector<ll> v(t.begin(), t.end());
        ll ans = 1e9;
        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (i) v[i] += v[i-1];
            ll x = v[i] - k;

            while(!pq.empty() && x >= pq.top()[0]) {
                ans = min(ans, i-pq.top()[1]);
                pq.pop();
            }

            pq.push({v[i], i});
        }

        return ans == 1e9 ? -1 : ans;
    }
};

// also with BIT

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Compressor {
    public:
        set<ll> v;
        map<ll, int> match;
        map<int, ll> inversedMatch;
        int last;

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

        BIT(vector<int> v) {
            tree = v;
            n = v.size();
        }   
        
        void update(int x, int val) {
            while(x<n) {
                tree[x] = max(tree[x], val);
                x+=(x)&(-x);
            }
        }

        int get(int x) {
            int res=-2;
            while(x>0) {
                res = max(tree[x], res);
                x-=(x)&(-x);
            }

            return res;
        }
};

class Solution {
public:
    int shortestSubarray(vector<int>& t, int k) {
        vector<ll> c = {0ll};

        vector<ll> v(t.begin(), t.end());

        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            if (v[i] == k)
                return 1;
            
            if (i)
                v[i] += v[i-1];

            c.push_back(v[i]);
            c.push_back(v[i]-k);
        }

        Compressor comp = Compressor(c);

        vector<int> a(comp.last, -2);
        BIT bit = BIT(a);

        for (int i=1 ; i<comp.last ; i++)
            bit.update(i, -2);

        bit.update(comp.match[0], -1);

        int ans = 1e9;
        for (int i=0 ; i<n ; i++) {
            int x = comp.match[v[i]-k];
            int mx = bit.get(x);

            if (mx > -2)
                ans = min(ans, i-mx);

            bit.update(comp.match[v[i]], i);
        }

        return ans == 1e9 ? -1 : ans;
    }
};

// deque
class Solution {
public:
    int shortestSubarray(vector<int>& t, int k) {
        deque<vector<ll>> dq = {{0, -1}};

        vector<ll> v(t.begin(), t.end());
        ll ans = 1e9;
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            if (i)
                v[i] += v[i-1];
            
            ll x = v[i] - k;

            while(!dq.empty() && x >= dq.front()[0]) {
                ans = min(ans, i-dq.front()[1]);
                dq.pop_front();
            }

            while(!dq.empty() && v[i] <= dq.back()[0]) {
                dq.pop_back();
            }

            dq.push_back({v[i], i});
        }

        return ans == 1e9 ? -1 : ans;
    }
};

int main() {
    vector<int> v = {2, -1, 2};
    cout<<Solution().shortestSubarray(v, 3);
}