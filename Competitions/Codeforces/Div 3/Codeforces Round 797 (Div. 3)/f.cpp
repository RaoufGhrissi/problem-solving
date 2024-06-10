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

ll lcm(ll a, ll b)
{
    return a*b/__gcd(a,b);
}

const int N = 200+7;
int graph[N];
bool vis[N];

int main()
{
    int t,n,k;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        string ch;
        cin>>ch;

        for (int i=0 ; i<n ; i++)
        {
            cin>>k;
            graph[--k]=i;
        }

        memset(vis, 0, sizeof vis);
        vector<int> cycle;
        vector<vector<int>> cycles;
        for (int i=0 ; i<n ; i++)
        {
            if (!vis[i])
            {
                int c=i;
                while(graph[c]!=i)
                {
                    vis[c]=1;
                    cycle.pb(c);
                    c=graph[c];
                }
                cycle.pb(c);
            }
            if (!cycle.empty())
                cycles.pb(cycle);
            cycle.clear();
        }

        ll ans=1;
        for (auto a:cycles)
        {
            string copie=ch;
            int m=a.size();
            int last=copie[a[m-1]];
            bool same=0;
            int itt=0;
            while(!same)
            {
                itt++;
                for (int i=m-1 ; i>0 ; i--)
                {
                    copie[a[i]]=copie[a[i-1]];
                }
                copie[a[0]]=last;
                last=copie[a[m-1]];
                same=1;
                for (int i=m-1 ; i>-1 ; i--)
                {
                    if (copie[a[i]] != ch[a[i]])
                    {
                        same=0;
                        break;
                    }
                }
            }

            ans=lcm(ans,itt);
        }

        cout<<ans;
        newL;
    }


    return 0;
}