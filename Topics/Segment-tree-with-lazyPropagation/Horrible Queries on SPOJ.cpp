// Problem link | SPOJ : https://www.spoj.com/problems/HORRIBLE/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

const int N = 1e5 + 5;

ll t,n,c,p,q,v,type;

struct node {
    ll sum;
    ll lazy;
    bool update;

    node(){
        sum=0;
        lazy=0;
        update=false;
    }

    node(ll _sum, ll _lazy, bool _update)
    {
        sum = _sum;
        lazy = _lazy;
        update = _update;
    }
};

node tree[4*N];

node mergee(node &l, node &r)
{
    return node(l.sum+r.sum,0,false);
}

void unlazy(int id, int ns=0, int ne=n-1)
{
    if (!tree[id].update)
        return ;

    if (ns!=ne) //having children
    {
        int left = 2*id + 1;
        int right = left + 1;
        int mid = (ns+ne)/2;

        tree[left].update = true;
        tree[right].update = true;

        tree[left].lazy+=tree[id].lazy;
        tree[right].lazy+=tree[id].lazy;

        tree[left].sum+=(mid-ns+1)*tree[id].lazy;
        tree[right].sum+=(ne-mid)*tree[id].lazy;
    }

    tree[id].lazy=0;
    tree[id].update = false;
}

void update(int qs, int qe, ll val, int id=0, int ns=0, int ne=n-1)
{
    unlazy(id,ns,ne);

    if (qs>ne || qe<ns)
        return ;

    if (qs<=ns && ne<=qe)
    {
        tree[id].sum+=val*(ne-ns+1);
        tree[id].lazy+=val;
        tree[id].update=true;

        return ;
    }

    int left = 2*id + 1;
    int right = left + 1;
    int mid = (ns+ne)/2;

    update(qs,qe,val,left,ns,mid);
    update(qs,qe,val,right,mid+1,ne);

    tree[id]=mergee(tree[left],tree[right]);
}

node query(int qs, int qe, int id=0 , int ns=0, int ne=n-1)
{
    unlazy(id,ns,ne);

    if (qe<ns || qs>ne)
        return node(0,0,false);

    if (qs<=ns && ne<=qe)
        return tree[id];

    int left = 2*id + 1;
    int right = left + 1;
    int mid = (ns+ne)/2;

    node q1 = query(qs,qe,left,ns,mid);
    node q2 = query(qs,qe,right,mid+1,ne);

    return mergee(q1,q2);
}

int main()
{
    Raouf;
    freopen("a.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        for (int i=0 ; i<4*N ; i++)
            tree[i]=node();

        cin>>n>>c;
        while(c--)
        {
            cin>>type>>p>>q;
            p--;
            q--;
            if (!type)
            {
                cin>>v;
                update(p,q,v);
            }
            else
            {
                cout<<query(p,q).sum<<'\n';
            }
        }
    }
    return 0;
}
