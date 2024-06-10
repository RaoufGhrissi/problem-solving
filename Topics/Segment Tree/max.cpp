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
#define fornll(j,n) for (ll i=j ; i<n ; i++)

using namespace std;
ll t,n,m,q;

const int N = 2*1e5+3;

int tree[4*N];
int a[N];

void build(int id=0, int ns=0, int ne=n-1)
{
    if (ns==ne)
    {
        tree[id]=a[ns];
        return ;
    }

    int left = id*2+1;
    int right = left+1;
    int mid = (ns+ne)/2;
    build(left,ns,mid);
    build(right,mid+1,ne);

    tree[id]=max(tree[left], tree[right]);
}

int query(int qs, int qe, int id=0, int ns=0, int ne=n-1)
{
    if (qs>ne || qe<ns)
        return 0;

    int left = id*2+1;
    int right = left+1;
    int mid = (ns+ne)/2;

    if (qs<=ns && ne<=qe)
        return tree[id];

    int q1 = query(qs,qe,left,ns,mid);
    int q2 = query(qs,qe,right,mid+1,ne);

    return max(q1, q2);
}


int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--)
    {        
    }

    return 0;
}
