// problem link: https://codeforces.com/contest/1702/problem/G2

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

int t,n,k,m;
const int N=2*1e5 + 5;
const int l=30;
int depth[N];
vector<int> graph[N];
vector<int> up[N];

void dfs(int node, int p)
{
    if (p!=-1)
    {
        depth[node]=depth[p]+1;
        up[node][0]=p;
    }

    for (int i=1 ; i<l ; i++)
        up[node][i] = up[up[node][i-1]][i-1];

    for (auto c:graph[node])
    {
        if (c != p)
            dfs(c, node);
    }

    return ;
}

int kthanc(int node, int k)
{
    for (int i=l-1 ; i>-1 ; i--)
    {
        if (k&(1<<i))
            node=up[node][i];
    }

    return node;
}

int lca(int a, int b)
{
    if (depth[a]<depth[b])
        swap(a,b); // a should have the max depth

    int diff = depth[a]-depth[b];

    if (diff)
        a = kthanc(a, diff);

    if (a==b)
        return a;

    for (int i=l-1 ; i>-1 ; i--)
    {
        int ca=up[a][i];
        int cb=up[b][i];
        if (ca != cb)
        {
            a=ca;
            b=cb;
        }
    }

    return up[a][0];
}

int dist(int a, int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
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

        for (int i=0 ; i<n-1 ; i++)
        {
            cin>>k>>m;
            k--;
            m--;
            graph[k].pb(m);
            graph[m].pb(k);
        }

        dfs(0,-1);

        int q;
        cin>>q;
        vector<int> v;
        while(q--)
        {
            cin>>k;
            v.clear();
            v.resize(k);

            for (int i=0 ; i<k ; i++)
            {
                cin>>v[i];
                v[i]--;
            }

            int nodeWithMAxDepth=v[0];
            for (int i=1 ; i<k ; i++)
            {
                if (depth[nodeWithMAxDepth]<depth[v[i]])
                    nodeWithMAxDepth=v[i];
            }
            int secondNodeWithMaxDepth=-1;
            for (int i=0 ; i<k ; i++)
            {
                if (lca(v[i], nodeWithMAxDepth) != v[i])
                {
                    if (secondNodeWithMaxDepth == -1)
                        secondNodeWithMaxDepth = v[i];
                    else if (depth[secondNodeWithMaxDepth]<depth[v[i]])
                        secondNodeWithMaxDepth=v[i];
                }
            }

            if (secondNodeWithMaxDepth == -1)
                cout<<"YES";
            else
            {
                bool ok = 1;
                for (auto a:v)
                {
                    if (dist(nodeWithMAxDepth,a)+dist(a,secondNodeWithMaxDepth) != dist(nodeWithMAxDepth, secondNodeWithMaxDepth))
                    {
                       ok=0;
                       break;
                    }
                }

                if (ok)
                    cout<<"YES";
                else
                    cout<<"NO";
            }
            newL;
        }
    }

    return 0;
}
