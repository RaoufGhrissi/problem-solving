#include <bits/stdc++.h>
using namespace std;
const int N=300;
int n;
vector<vector<int>> graph;
int p[N];
bool vis[N];
bool used[N];
int indexToSwapWith;
int minn;

void dfs(int pos)
{
    vis[pos]=true;
    if (!used[pos] && p[pos]<minn)
    {
        indexToSwapWith = pos;
        minn = p[pos];
    }

    for (int i=0 ; i<graph[pos].size(); i++)
    {
        int x=graph[pos][i];
        if (!vis[x])
            dfs(x);
    }
    return ;
}

int main() {
    cin>>n;
    graph.resize(n);
    memset(used,false,sizeof(used));

    for (int i=0; i<n ; i++)
    {
        int a;
        cin>>a;
        a--;
        p[i]=a;
    }

    for (int i=0; i<n ; i++)
    {
        string s;
        cin>>s;
        for (int j=0 ; j<n ; j++)
        {
            if (s[j]=='1')
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i=0 ; i<n ; i++)
    {
        memset(vis,false,sizeof(vis));
        minn=INT_MAX;
        dfs(i);
        swap(p[i],p[indexToSwapWith]);
        used[i]=true;
    }

    for (int i=0 ; i<n ; i++)
        cout<<p[i]+1<<" ";

    return 0;
}
