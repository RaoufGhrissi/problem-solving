#include<bits/stdc++.h>
using namespace std;
const int N=407;
int n,m;
vector<int> graph[N];
bool vis[N];

void dfs(int pos)
{
    vis[pos]=true;
    for (int i=0 ; i<graph[pos].size() ; i++)
    {
        int x=graph[pos][i];
        if (!vis[x])
            dfs(x);
    }
    return;
}


int main(){
    cin>>n>>m;
    int node=0;
    int nextNode = m;

    for (int i=0 ; i<n ; i++)
    {
        char a;
        cin>>a;
        for (int j=node ; j<nextNode-1; j++)
        {
            if (a=='>')
            {
                //cout<<j<<"->"<<j+1<<endl;
                graph[j].push_back(j+1);
            }
            else
            {
                //cout<<j+1<<"->"<<j<<endl;
                graph[j+1].push_back(j);
            }
        }
        node=nextNode;
        nextNode+=m;
    }

    node=0;
    nextNode=(n-2)*m;
    for (int i=0 ; i<m ; i++)
    {
        char a;
        cin>>a;
        for (int j=node ; j<=nextNode; j+=m)
        {
            if (a=='v')
            {
                //cout<<j<<"->"<<j+m<<endl;
                graph[j].push_back(j+m);
            }
            else
            {
                //cout<<j+m<<"->"<<j<<endl;
                graph[j+m].push_back(j);
            }
        }
        node++;
        nextNode++;
    }

    int v=n*m;
    for (int pos=0 ; pos<v; pos++)
    {
        memset(vis, false,sizeof(vis));
        dfs(pos);
        for (int i=0 ; i<v ; i++)
        {
            if (!vis[i])
            {
                cout<<"NO";
                return 0;
            }
        }
    }


    cout<<"YES";
    return 0;
}
