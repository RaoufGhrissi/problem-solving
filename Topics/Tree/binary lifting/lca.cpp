// problem link: https://www.spoj.com/problems/LCASQ/
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define Pair pair<ll,ll>
#define iPair pair<int,int>
#define newL cout<<endl
#define ll_max 1e18
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define forn(j,n) for (int i=j ; i<n ; i++)

using namespace std;

ll t,n,k,m;
const int N=1e4 + 5;
const int l=15;
int depth[N];
vector<int> graph[N];
vector<int> up[N];

void dfs(int node, int p)
{
    if (p==-1)
        up[node][0]=0;
    else
        up[node][0]=p;

    for (int i=1 ; i<l ; i++)
        up[node][i] = up[up[node][i-1]][i-1];

    for (auto c:graph[node])
    {
        if (c != p)
        {
            depth[c]=depth[node]+1;
            dfs(c, node);
        }
    }
}

int kthanc(int node, int k)
{
    if (k>depth[node])
        return -1;

    int l=log2(k);
    for (int i=l ; i>-1 ; i--)
    {
        if (k&(1<<i))
            node=up[node][i];
    }

    return node;
}

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--)
    {
        cin>>n;
        for (int i=0 ; i<n ; i++)
        {
            graph[i].clear();
            depth[i]=0;
            up[i].clear();
            up[i].resize(l);
        }

        for (int i=0 ; i<n ; i++)
        {
            cin>>k;

            while(k--)
            {
                cin>>m;
                graph[i].pb(m);
                graph[m].pb(i);
            }
        }

        dfs(0,-1);

        int q;
        cin>>q;

        while(q--)
        {
            int a,b;
            cin>>a>>b; // a with greater depth
            if (depth[a]<depth[b])
                swap(a,b);

            int diff = depth[a]-depth[b];

            a = kthanc(a,diff);
            if (a==b)
            {
                cout<<a;
                newL;
                continue;
            }

            for (int i=l ; i>-1 ; i--)
            {
                int ca=up[a][i];
                int cb=up[b][i];
                if ( ca != cb)
                {
                    a=ca;
                    b=cb;
                }
            }
            cout<<up[a][0];
            newL;
        }
    }

    return 0;
}
