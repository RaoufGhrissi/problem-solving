#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define Inf (ll)(999999)

using namespace std;

const int N = 26;
vector<vector<int>> graph;
int dist[N][N];
bool visited[26];

void augmentedBfs (int src){
	queue<int> q;
    q.push(src);

    visited[src]=true;

    dist[src][src]=0;

	while (!q.empty()){
        int parent = q.front();
        q.pop();
        for (auto child:graph[parent])
        {
             if (!visited[child])
             {
                 visited[child]=true;
                 q.push(child);

                 dist[src][child]=1+dist[src][parent];
             }
        }
	}
}

int main(){

freopen("a.txt","r",stdin);
freopen("a.out","w",stdout);

int n,k;
string s,ch;
int occ[N];
cin>>n;

for (int cas=1 ; cas<=n ; cas++)
{
    cin>>s>>k;
    memset(occ, 0, sizeof occ);
    for (int i=0 ; i<s.size() ; i++)
        occ[s[i]-'A']++;

    for (int i=0 ; i<N ; i++)
    {
        for (int j=0 ; j<N ; j++)
        {
            if (i==j)
                dist[i][j]=0;
            else
                dist[i][j]=Inf;
        }
    }
    graph.clear();
    graph.resize(N);
    while(k--)
    {
        cin>>ch;
        graph[ch[0]-'A'].pb(ch[1]-'A');
    }
    for (int i=0 ; i<26 ; i++)
    {
        if (occ[i]!=0)
        {
            memset(visited, 0, sizeof visited);
            augmentedBfs(i);
        }
    }

    vector<int> canBeDestination;

    for (int j=0 ; j<N ; j++)
    {
        bool ok = true;
        for (int i=0 ; i<N ; i++)
        {
            if (occ[i] == 0)
                continue;
            if (dist[i][j] == Inf)
            {
                ok = false;
                break;
            }
        }
        if (ok)
           canBeDestination.push_back(j);
    }
    int ans=INT_MAX;
    if (canBeDestination.empty())
    {
        cout<<"Case #"<<cas<<": "<<-1<<'\n';
        continue;
    }
    for(auto a:canBeDestination)
    {
        int c=0;
        for (int i=0 ; i<N ; i++)
        {
            if (occ[i]==0)
                continue;
            c+=dist[i][a]*occ[i];
        }
        ans=min(ans,c);
    }

    cout<<"Case #"<<cas<<": "<<ans<<'\n';
}

    return 0;
}
