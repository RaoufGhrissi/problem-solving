#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
int q,n,l,r;
int a[N];

struct node{
    int ml;
    int occMl;
    int mr;
    int occMr;
    int occ;

    node()
    {
        ml=0;
        occMl=0;
        mr=0;
        occMr=0;
        occ=0;
    }

    node(int l,int occl, int r,int occr, int o)
    {
        ml=l;
        occMl=occl;
        mr=r;
        occMr=occr;
        occ=o;
    }
};

node tree[4*N];

node mergee(node &l, node &r)
{
    node nd = node(l.ml,l.occMl, r.mr, r.occMr, max(l.occ, r.occ));

    if (l.mr == r.ml)
        nd.occ = max(nd.occ,l.occMr+r.occMl);

    if (l.ml == r.ml)
        nd.occMl+=r.occMl;

    if (r.mr == l.mr)
        nd.occMr+=l.occMr;

    return nd;
}

void build(int id=0, int ns=0, int ne=n-1)
{
    if (ns==ne)
    {
        tree[id]=node(a[ns],1,a[ns],1,1);
        return ;
    }

    int l=2*id+1;
    int r=l+1;
    int mid=(ns+ne)/2;

    build(l,ns,mid);
    build(r,mid+1,ne);

    tree[id]=mergee(tree[l],tree[r]);
}

node query(int qs, int qe, int id = 0, int ns=0, int ne=n-1)
{
    if (qs>ne || qe<ns)
        return node();

    if (qs<=ns && ne<=qe)
        return tree[id];

    int l=2*id+1;
    int r=l+1;
    int mid = (ns+ne)/2;

    node n1 = query(qs,qe,l,ns,mid);
    node n2 = query(qs,qe,r,mid+1,ne);

    return mergee(n1,n2);

}

int main()
{
    //freopen("a.txt", "r", stdin);

    while(1)
    {
        scanf("%d",&n);

        if (!n)
            break;

        scanf("%d",&q);
        for(int i=0 ; i<n ; i++)
            scanf("%d",&a[i]);

        build();
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(--l,--r).occ);
        }
    }

    return 0;

}
