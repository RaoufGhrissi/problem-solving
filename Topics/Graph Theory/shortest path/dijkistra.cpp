#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define INF (ll)1e18

using namespace std;

const int N = 1e5+7;
int n,m;
ll dist[N];

vector<vector<pp>> graph;

void dijkistra(int node)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    for (int i=0 ; i<n ; i++)
    {
        if (i == node)
            dist[i]=0;
        else
            dist[i] = INF;
    }

    pq.push({dist[node], node});

    while(!pq.empty())
    {
        pp parent = pq.top();
        pq.pop();

        int h = parent.first;
        ll index = parent.second;

        if (h>dist[index])
            continue;

        for (auto childPair:graph[index])
        {
            ll child = childPair.first;
            ll dFromParentToChild = childPair.second;
            if (dist[child]>dist[index]+dFromParentToChild)
            {
                dist[child] = dist[index]+dFromParentToChild;
                pq.push({dist[child], child});
            }

        }
    }
}

int main()
{
    freopen("a.txt", "r", stdin);
    cin>>n>>m;
    graph.resize(n);
    int a,b,d;

    while(m--)
    {
        cin>>a>>b>>d;
        a--;
        b--;
        graph[a].pb({b,d});
        graph[b].pb({a,d});
    }

    dijkistra(0);

    for (int i=1 ; i<n ; i++)
        cout<<"distance from 0 to "<<i<<" = "<<dist[i]<<'\n';

}
