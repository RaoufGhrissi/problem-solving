#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;

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

const int N = 1e5 + 1;
int cycle[N];
vector<int> graph[N];
bool vis[N];
int parent[N];
int touchedCycle[N];
int matching[N];
int ssize[N];
int cycleCnt[N];
int cycleStart, id = 1;
vector<int> cyclesStarts;

void dfs(int field) {
    vis[field] = 1;

    int nxt = parent[field];
    if (nxt) {
        if (vis[nxt] && !cycle[nxt]) {
            cycleStart = nxt;
            cyclesStarts.push_back(cycleStart);
        } else {
            dfs(parent[field]);
        }
    }

    if (cycleStart) {
        cycle[field] = cycleStart;
        if (field == cycleStart)
            cycleStart = 0;
    }
}

void mark(int field, int &start) {
    touchedCycle[field] = start;
    for (int &child:graph[field]) {
        mark(child, start);
    }
}

int dfs0(int field) {
    ssize[field] = 1;
    matching[field] = id++;

    int nxt = parent[field];
    if (nxt && !cycle[nxt]) {
        ssize[field] += dfs0(nxt);
    }

    return ssize[field];
}

int main() {
    ll t,n;
    FAST;
    freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        for (int i=1 ; i<=n ; i++) {
            cin>>parent[i];
            if (parent[i])
                graph[parent[i]].push_back(i);

            vis[i] = 0;
            cycle[i] = 0;
            cycleCnt[i] = 0;
        }

        //create fake self loop
        for (int i=1 ; i<=n ; i++) {
            if (graph[i].empty()) {
                cycleStart = 0;
                dfs(i);
            }
        }

        for (int i=1 ; i<=n ; i++) {
            if (graph[i].empty()) {
                cycleStart = 0;
                dfs(i);
            }
        }

        for (int &cs:cyclesStarts)
            mark(cs, cs);

        for (int i=1 ; i<=n ; i++) {
            if (graph[i].empty()) {
                dfs0(i);
            }
        }

        BIT bit = BIT(n+1);

        while(q--) {
            int type, field;
            cin>>type>>field;

            if (type == 1) {
                int l = matching[field];
                int r = l + ssize[field]-1;
                bit.update(l, 1);
                if (r+1 <= n)
                    bit.update(r+1, -1);

                if (touchedCycle[field]) {
                    cycleCnt[touchedCycle[field]]++;
                }
            } else {
                int l = matching[field];
                int ans = bit.get(l);
                if (l > 1) {
                    ans -= bit.get(l-1);
                }

                ans += cycleCnt[cycle[field]];

                cout<<ans<<endl;    
            }
        }

        
    }

    return 0;
}