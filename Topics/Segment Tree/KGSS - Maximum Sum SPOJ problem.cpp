#include <bits/stdc++.h>

using namespace std;
#define Pair pair<int,int>

const int N = 1e5+3;
const int inf = 1e7;
int n,q,l,r,i;
char opp;

Pair tree[4*N];
int a[N];

void build(int id=0, int ns=0, int ne=n-1)
{
    if (ns==ne)
    {
        tree[id].first=a[ns];
        tree[id].second=-inf;
        return ;
    }

    int left = id*2+1;
    int right = left+1;
    int mid = (ns+ne)/2;
    build(left,ns,mid);
    build(right,mid+1,ne);

    vector<int> v = {tree[left].first, tree[left].second, tree[right].first, tree[right].second};
    sort(v.begin(), v.end());

    tree[id].first=v[2];
    tree[id].second=v[3];
}

void update(int pos, int val, int id=0, int ns=0, int ne=n-1)
{
    if (pos<ns || pos>ne)
        return ;

    if (ns==ne)
    {
        tree[id].first=val;
        tree[id].second=-inf;
        return ;
    }

    int left = id * 2 + 1;
    int right = left + 1;
    int mid = (ns+ne)/2;

    update(pos,val,left,ns,mid);
    update(pos,val,right,mid+1,ne);

    vector<int> v = {tree[left].first, tree[left].second, tree[right].first, tree[right].second};
    sort(v.begin(), v.end());

    tree[id].first=v[2];
    tree[id].second=v[3];
}

Pair query(int qs, int qe, int id=0, int ns=0, int ne=n-1)
{
    if (qs>ne || qe<ns)
        return {-inf,-inf};

    int left = id*2+1;
    int right = left+1;
    int mid = (ns+ne)/2;

    if (qs<=ns && ne<=qe)
        return {tree[id].first,tree[id].second};

    Pair q1 = query(qs,qe,left,ns,mid);
    Pair q2 = query(qs,qe,right,mid+1,ne);

    vector<int> v = {q1.first, q1.second, q2.first, q2.second};
    sort(v.begin(), v.end());
    return {v[2], v[3]};
}

int main()
{
    cin>>n;
    for (i=0 ; i<n ; i++)
        cin>>a[i];

    build();
    cin>>q;
    while(q--)
    {
        cin>>opp>>l>>r;
        switch(opp){
        case 'Q':
            {
                Pair p = query(--l,--r);
                cout<<p.first+p.second<<endl;
                break;
            }
        case 'U':
            {
                update(--l,r);
                break;
            }
        }
    }


    return 0;
}
