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
const int N = 1e5 + 7;
const int inf = 1e9 + 7;
int tree[4*N];
int a[N];
int k,d,n,m,t;
set<int> trains;

void build(int id=0, int ns=0, int ne=n-1)
{
    if(ns==ne)
    {
        tree[id]=a[ns];
        return ;
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    build(l, ns, md);
    build(r, md+1,ne);
    tree[id]=min(tree[l],tree[r]);
}

void update(int p, int v, int id=0,int ns=0, int ne=n-1)
{
    if(p>ne || p<ns)
        return ;

    if(ns==ne)
    {
        tree[id]=v;
        return ;
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    update(p, v, l, ns, md);
    update(p, v, r, md+1,ne);
    tree[id]=min(tree[l],tree[r]);
}

int query(int qs, int qe, int id=0, int ns=0,int ne=n-1)
{
    if(qs>ne || qe<ns)
        return inf;

    if(qs<=ns && qe>=ne)
        return tree[id];

    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    return min(query(qs, qe, l, ns, md), query(qs, qe, r, md+1,ne));
}

bool isTrain(int i)
{
    return i==0 || query(0,i-1)>a[i];
}

void addTrain(int i)
{
    trains.insert(i);
    set<int> toRemove;
    auto it =trains.find(i);
    it++;
    while(it!=trains.end())
    {
        if(a[*it]>=a[i])
            toRemove.insert(*it);
        else
            break;
        it++;
    }

    for(auto u:toRemove)
    {
        trains.erase(u);
    }
}

void remTrain(int i)
{
    trains.erase(i);
}

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;
    while(t--)
    {
        trains.clear();
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];

        build();

        for(int i=0;i<n;i++)
        {
            if(isTrain(i))
                addTrain(i);
        }

        while(m--)
        {
            cin>>k>>d;
            k--;
            if(isTrain(k))
                remTrain(k);

            a[k]-=d;
            update(k,a[k]);

            if(isTrain(k))
                addTrain(k);

            cout<<trains.size()<<" ";
        }
        newL;
    }

    return 0;
}