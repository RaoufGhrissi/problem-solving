#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
ll t,n,m,k;
string c;
const int N=4*1e4+5;
vector<ll> graph[N];
bool vis[N];
int black[N];
int white[N];

void dfs(int p)
{
    vis[p]=true;

    for (auto child:graph[p])
    {
        if (!vis[child])
        {
            dfs(child);
            black[p]+=black[child];
            white[p]+=white[child];
        }
    }

    black[p]+=c[p]=='B';
    white[p]+=c[p]=='W';
}


int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;

        for (int i=0 ; i<n ; i++)
            graph[i].clear();

        for (int i=1 ; i<n ; i++)
        {
            cin>>m;
            graph[--m].pb(i);
        }
        cin>>c;
        memset(vis,0,sizeof vis);
        memset(black,0,sizeof black);
        memset(white,0,sizeof white);

        dfs(0);
        ll ans=0;
        for (int i=0 ; i<n ; i++)
        {
            if (black[i]==white[i])
                ans++;
        }

        cout<<ans;
        newL;
    }


    return 0;
}