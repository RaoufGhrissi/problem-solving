#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define INF (ll)(1e18)

using namespace std;

const int N = 1e5+7;
int n,m;
vector<int> graph[N];
bool visited[N];
int dist[N];

void augmentedBfs (int src, int dest){
	queue<int> q;
    q.push(src);
    visited[src]=true;
    dist[src]=0;

	while (!q.empty()){
        int parent = q.front();
        q.pop();
        for (auto child:graph[parent])
        {
             if (!visited[child])
             {
                 visited[child]=true;
                 q.push(child);
                 dist[child]=1+dist[parent];
             }
        }
	}
}

int main()
{
cin>>n>>m;
int mMax;
if (n==m)
{
   cout<<0;
   return 0;
}
else if (n>m)
{
   cout<<n-m;
   return 0;
}
else
    mMax = (m-1)*2;

for (int i=1 ; i<=mMax ; i++)
{
    if (i-1>0) graph[i].pb(i-1);
    if (2*i<=mMax) graph[i].pb(2*i);
}

for (int i=0 ; i<=N ; i++)
    dist[i]=INF;

memset(visited, 0, sizeof visited);

augmentedBfs(n,m);

cout<<dist[m];

    return 0;
}