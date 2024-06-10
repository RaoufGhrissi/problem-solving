#include <bits/stdc++.h>

using namespace std;
const int N = 3 * 1e4 + 7;
int t=10,n,m,a;
string s;

struct node {
    int opened;
    int closed;

    node(){
        opened=0;
        closed=0;
    }

    node(int o, int c){
        opened=o;
        closed=c;
    }
};

node tree[4*N];

node mergee(node &l, node &r)
{
    node nd = node(r.opened, l.closed);
    int diff = l.opened - r.closed;
    if (diff>0)
        nd.opened+=diff;
    else
        nd.closed-=diff;

    return nd;
}

void build(int id=0, int ns=0, int ne=n-1)
{
    if (ns==ne)
    {
        tree[id]=node(s[ns]=='(',s[ns]==')');
        return ;
    }

    int l=2*id+1;
    int r=l+1;
    int mid=(ns+ne)/2;

    build(l,ns,mid);
    build(r,mid+1,ne);

    tree[id]=mergee(tree[l],tree[r]);
}

void update(int pos, int id=0, int ns=0, int ne=n-1)
{
    if (pos>ne || pos<ns)
        return;

    if (ns==ne)
    {
        char inverse;
        if (s[ns]=='(')
            inverse = ')';
        else
            inverse = '(';

        s[ns]=inverse;

        tree[id]=node(s[ns]=='(',s[ns]==')');

        return ;
    }

    int l=2*id+1;
    int r=l+1;
    int mid=(ns+ne)/2;

    update(pos,l,ns,mid);
    update(pos,r,mid+1,ne);

    tree[id]=mergee(tree[l],tree[r]);
}

int main()
{
    freopen("a.txt","r",stdin);
    for (int i=1 ; i<=1 ; i++)
    {
        cin>>n>>s>>m;
        cout<<"Test "<<i<<":\n";
        build();

        while(m--)
        {
            cin>>a;
            if (a==0)
            {
                if (tree[0].closed == 0 && tree[0].opened == 0)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                update(--a);
        }
    }

    return 0;
}
