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

const int N=2*1e5+5;
ll tree[N];

void update(int x, int val)
{
    while(x<=N)
    {
        tree[x]+=val;
        x+=(x)&(-x);
    }
}

ll get_sum(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=tree[x];
        x-=(x)&(-x);
    }

    return res;
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
        vector<ll> v(n);
        memset(tree, 0, sizeof(tree));
        for (int i=0 ; i<n ; i++)
        {
            cin>>v[i];
            update(v[i],1);
        }
        ll ans=0;
        for (int i=0 ; i<n ; i++)
        {
            update(v[i],-1);
            ans+=get_sum(v[i]);
        }

        cout<<ans;

        newL;
    }


    return 0;
}