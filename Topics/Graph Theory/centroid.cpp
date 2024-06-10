#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define INF (ll)1e18

using namespace std;

const int N = 1e5+7;
int n,m;
int sizee[N];

vector<int> graph[N];

int dfsBuildSize(int node, int parent)
{
    sizee[node]=1;
    for (auto child:graph[node])
    {
        if (child != parent)
            sizee[node]+=dfsBuildSize(child,node);
    }

    return sizee[node];
}

int dfsCentroid(int node, int parent)
{
    for (auto child:graph[node])
    {
        if (child != parent && sizee[child]>sizee[node]/2)
            return dfsCentroid(child,node);
    }

    return node;
}

int main()
{
    freopen("a.txt", "r", stdin);
    cin>>n>>m;
    int a,b;

    while(m--)
    {
        cin>>a>>b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfsBuildSize(0,-1);

    for (int i=0 ; i<n ; i++)
        cout<<sizee[i]<<" ";

    cout<<endl;

    cout<<dfsCentroid(0,-1)+1;

}

