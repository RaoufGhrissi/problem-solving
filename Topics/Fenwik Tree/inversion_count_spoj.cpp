#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define Pair pair<ll,ll>
#define iPair pair<int,int>
#define newL cout<<'\n'
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

const int N=1e7+5;
const int M=2*1e5+5;
int a[M];
ll tree[N];
int t,n;

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

    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        memset(tree, 0, sizeof(tree));
        ll ans=0;
        for (int i=n-1 ; i>-1 ; i--)
        {
            ll summ = get_sum(a[i]-1);
            ans+=summ;
            update(a[i],1);
        }


        cout<<ans;


        newL;
    }


    return 0;
}
