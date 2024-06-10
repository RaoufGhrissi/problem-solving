#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
vector<int> graph[N];
int cats[N];
bool vis[N] ;
int n,m,ans,a,b;

bool isLeaf(int parent)
{
    for (auto child:graph[parent])
    {
        if (!vis[child])
            return false;
    }

    return true;
}

void dfs(int parent)
{
    vis[parent]=true;

    if (cats[parent]>m)
        return;

    if (isLeaf(parent) && cats[parent]<=m)
        ans++;

    for (auto child:graph[parent])
    {
        if (!vis[child])
        {
            if (cats[child])
                cats[child]+=cats[parent];
            dfs(child);
        }
    }

    return ;
}



int main()
{
cin>>n>>m;

memset(vis,false,sizeof vis);

for (int i=0 ; i<n ; i++)
    cin>>cats[i];

for (int i=0 ; i<n-1 ; i++)
{
    cin>>a>>b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
}

ans=0;
dfs(0);
cout<<ans;

return 0;
}
