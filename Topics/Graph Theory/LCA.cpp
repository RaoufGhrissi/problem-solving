#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long

const int N = 1e5;

int n,n1,n2;
vector<int> graph[N];
vector<int> v1;
vector<int> v2;

void add(int a, int b)
{
    graph[a].pb(b);
    graph[b].pb(a);
}

void dfs(int node, int parent, vector<int> &v)
{
    v.pb(node);

    if (node == n1)
    {
        v1=v;
    }
    else if (node == n2)
    {
        v2=v;
    }

    for (auto child:graph[node])
    {
        if (child != parent)
            dfs(child,node,v);
    }
    auto it = find(v.begin(), v.end(), node);
    v.erase(it,it+1);
    return;
}


int main()
{
    freopen("a.txt", "r", stdin);
    cin>>n;
    for (int i=0 ; i<n-1 ; i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }

    cin>>n1>>n2;

    vector<int> v;
    dfs(0,-1, v);

    int s = min(v1.size(),v2.size());

    if (v1[s-1] == v2[s-1])
    {
        cout<<v1[s-1];
    }

    for (int i=1 ; i<s; i++)
    {
        if (v1[i]!=v2[i])
        {
            cout<<v1[i-1];
        }
    }


    return 0;
}
