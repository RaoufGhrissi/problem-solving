#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int t,n;
vector<vector<int>> graph;
vector<int> coins;
int m=0;
bool vis[N];
int val[N];

void dfs(int parent)
{
    vis[parent] = true;
    m = max(m,coins[parent]);
    for(auto child:graph[parent])
    {
        if (!vis[child])
        {
            coins[child]+=coins[parent];
            dfs(child);
        }
    }
    return;
}

int main(){

freopen("a.txt","r",stdin);
freopen("a.out","w",stdout);

cin>>t;
for (int cas=1 ; cas<=t ; cas++)
{
    cin>>n;
    graph.clear();
    graph.resize(n+5);
    coins.clear();
    coins.resize(n+5);

    for(int i=1 ; i<=n ; i++)
        cin>>coins[i];

    for(int i=0 ; i<n-1 ; i++)
    {
        int s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    memset(vis,0,sizeof vis);
    vis[1]=true;
    vector<int> res;
    for (auto child:graph[1])
    {
        m = 0;
        dfs(child);
        res.push_back(m);
    }

    sort(res.begin(), res.end(), greater<int>());
    int ans = coins[1];
    for (int i=0 ; i<min(2,(int)res.size()); i++)
        ans+=res[i];

    cout<<"Case #"<<cas<<": "<<ans<<'\n';
}
    return 0;
}
